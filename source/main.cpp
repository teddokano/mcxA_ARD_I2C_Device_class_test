/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include	"r01lib.h"
#include	"test_LM75B.h"

I2C			i2c( I2C_SDA, I2C_SCL );
test_LM75B	sensor( i2c, 0x4C );

int main(void)
{
	PRINTF("\r***** Hello, I2C_device! *****\r\n");

	I2C_device::scan( i2c, 124 ); //  Scan stop at 124

	float	temp;

	while ( true )
	{
		temp	= sensor.read();
		PRINTF( "%8.4f\r\n", temp );
		wait( 1 );
	}
}
