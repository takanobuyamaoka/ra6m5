/*
  EEPROM.cpp - EEPROM library
  Copyright (c) 2006 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/* Modified 20 April 2015 by Yuuki Okamiya for GR-SAKURA */
/* Modified 22 Feb. 2019 by Yuuki Okamiya for GR-ROSE */

/******************************************************************************
 * Includes
 ******************************************************************************/

extern "C" {
#include "r_flash_hp.h"
#include "hal_data.h"
}
#include "EEPROM.h"

/******************************************************************************
 * Definitions
 ******************************************************************************/

/******************************************************************************
 * Constructors
 ******************************************************************************/

/******************************************************************************
 * User API
 ******************************************************************************/

#define MASK_PGM   0xfffffffc
#define MASK_BLOCK 0xffffffc0

void isr_flash(flash_callback_args_t *p_args)
{

}
EEPROMClass::EEPROMClass(){
	_first_access = true;
}

uint8_t EEPROMClass::read(int address)
{
    fsp_err_t err;
    flash_result_t result;
    if (_first_access){
    	R_FLASH_HP_Open(&g_flash0_ctrl, &g_flash0_cfg);
    	_first_access = false;
    }
	err = R_FLASH_HP_BlankCheck(
	        &g_flash0_ctrl,
	        (uint32_t)BSP_FEATURE_FLASH_DATA_FLASH_START + (address & MASK_PGM),
	        BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE,
			&result);
	if( err != FSP_SUCCESS){
		//error
	} else {
		if(result == FLASH_RESULT_BLANK){
		    //blank
		    return 0xff;
		}
	}
	return *(volatile unsigned char *)(address + BSP_FEATURE_FLASH_DATA_FLASH_START);
}

void EEPROMClass::write(int address, uint8_t value)
{
	uint8_t wbuf[BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE];
	uint8_t rbuf[BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE]; // for block write
	uint8_t bbuf[BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE]; // for blank check
	uint32_t w_addr = address & MASK_PGM; // needed for blank check to target address
	uint32_t b_addr = address & MASK_BLOCK; // block address

    if (_first_access){
    	R_FLASH_HP_Open(&g_flash0_ctrl, &g_flash0_cfg);
    	_first_access = false;
    }
	for (int i = 0; i < BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE; i++){
	    if((address & (BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE-1)) == i){
	        wbuf[i] = value;
	    } else {
            wbuf[i] = this->read(w_addr + i);
	    }
	}

	flash_result_t result;
	if(R_FLASH_HP_BlankCheck(&g_flash0_ctrl, (uint32_t)BSP_FEATURE_FLASH_DATA_FLASH_START + w_addr,
	                         BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE, &result) != FSP_SUCCESS){
	} else {
		if(result == FLASH_RESULT_BLANK){
		    //blank
			R_FLASH_HP_Write(&g_flash0_ctrl, (uint32_t)wbuf, (uint32_t)BSP_FEATURE_FLASH_DATA_FLASH_START + w_addr, BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE);
		    return;
		} else {
		    // not blank, needed to read data in a block
		    for(uint8_t i = 0; i < BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE; i+=BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE){
		    	R_FLASH_HP_BlankCheck(&g_flash0_ctrl,
		    	                      (uint32_t)BSP_FEATURE_FLASH_DATA_FLASH_START + b_addr + i,
		    	                      BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE,
		    	                      &result);
		        if(result == FLASH_RESULT_BLANK){
		        	// blank, no need to read & write
	                bbuf[i] = 1;
		        } else {
		            // not blank, need to store the current data
	                bbuf[i] = 0;
	                if (i == (w_addr & (BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE-1))){
	                    for(int j = 0 ; j < BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE; j++){
	                        rbuf[i + j]   = wbuf[j];
	                    }
	                } else {
	                    for(int j = 0 ; j < BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE; j++){
	                        rbuf[i + j]   = this->read(b_addr + i + j);
	                    }
	                }
		        }
		    }
		    R_FLASH_HP_Erase(&g_flash0_ctrl, (BSP_FEATURE_FLASH_DATA_FLASH_START + (address & MASK_BLOCK)), 1);

		    for(int i = 0; i < BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE; i+=BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE){
	            if(bbuf[i]){ // do nothing because of blank

	            } else {
	                R_FLASH_HP_Write(&g_flash0_ctrl, (uint32_t)&rbuf[i], BSP_FEATURE_FLASH_DATA_FLASH_START + b_addr + i, BSP_FEATURE_FLASH_HP_DF_WRITE_SIZE);
	            }
	        }
		}
	}
	return;
}

void EEPROMClass::erase(){
    R_FLASH_HP_Erase(&g_flash0_ctrl, BSP_FEATURE_FLASH_DATA_FLASH_START, 128);
}
uint32_t EEPROMClass::length(){
	return 128 * BSP_FEATURE_FLASH_HP_DF_BLOCK_SIZE;
}

EEPROMClass EEPROM;
