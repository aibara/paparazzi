/*
 * $Id: $
 *
 * Copyright (C) 2009 Flixr
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#include "booz_drop.h"
#include "booz2_pwm_hw.h"


bool_t booz_drop_ball;
int16_t booz_drop_servo;

#define DROP_SERVO_OPEN 1700
#define DROP_SERVO_CLOSED 900

void booz_drop_init(void) {
  booz_drop_ball = FALSE;
  booz_drop_periodic();
}

void booz_drop_periodic(void) {
  if (booz_drop_ball == TRUE)
    booz_drop_servo = DROP_SERVO_OPEN;
  else
    booz_drop_servo = DROP_SERVO_CLOSED;
  Booz2SetPwmValue(booz_drop_servo);
}