/***
 * iRecovery++ libusb based usb interface for iBoot and iBSS
 * Copyright (C) 2010  GreySyntax
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef PROGRAM_H_

#define PROGRAM_H_

#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <ctype.h>
#include "IDevice.h"
#include "Common.h"

void conditions();
void flags();
void shutdown(int sig);
void warranty();

#endif /* PROGRAM_H_ */
