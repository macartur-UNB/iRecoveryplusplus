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

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "Program.h"
#include "IDevice.h"

using namespace std;

static IDevice Device;

int main(int argc, char *argv[]) {

	cout << "iRecovery++  Copyright (C) 2010  GreySyntax\r\n";
	cout << "This program comes with ABSOLUTELY NO WARRANTY; for details `./iRecovery -w'.\r\n";
	cout << "This is free software, and you are welcome to redistribute it\r\n";
	cout << "under certain conditions; type `./iRecovery -o' for details.\r\n" << endl;

	if (! (argc > 1)) {

		flags();
		return -1;
	}

	int c;

	while ((c = getopt(argc, argv, "acerosuwvh:")) != -1) {

		switch (c) {

			case 'a':
				if (! Device.IsConnected() && ! Device.Connect()) {

					return -1;
				}

				if (! Device.AutoBoot()) {

					return 1;
				}

				break;

			case 'c':
				if (! Device.IsConnected() && ! Device.Connect()) {

					return -1;
				}

				if (Device.SendCommand(optarg)) {

					continue;
				}

				break;

			case 'e':

				cout << "Not implemented. :(" << endl;
				break;

			case 'r':
				if (! Device.IsConnected() && ! Device.Connect()) {

					return -1;
				}

				Device.Reset();
				break;

			case 'o':
				conditions();
				break;

			case 's':
				if (! Device.IsConnected() && ! Device.Connect()) {

					return -1;
				}

				Device.Shell();
				break;

			case 'u':
				if (! Device.IsConnected() && ! Device.Connect()) {

					return -1;
				}

				if (! Device.Upload(optarg)) {

					continue;
				}
				break;

			case 'w':
				warranty();
				break;

			case 'v':
				cout << "iRecovery++ " << VERSION << "," << endl;
				cout << "Thanks to: lilstevie, pod2g, tom3q, planetbeing, geohot, posixninja and westbaer." << endl << endl;
				break;

			case '?':
			case 'h':
				flags();
				break;
		}
	}

	return 1;
}

void conditions() {

	cout << "All rights granted under this License are granted for the term of\r\n";
	cout << "copyright on the Program, and are irrevocable provided the stated\r\n";
	cout << "conditions are met.  This License explicitly affirms your unlimited\r\n";
	cout << "permission to run the unmodified Program.  The output from running a\r\n";
	cout << "covered work is covered by this License only if the output, given its\r\n";
	cout << "content, constitutes a covered work.  This License acknowledges your\r\n";
	cout << "rights of fair use or other equivalent, as provided by copyright law.\r\n";

	cout << "You may make, run and propagate covered works that you do not\r\n";
	cout << "convey, without conditions so long as your license otherwise remains\r\n";
	cout << "in force.  You may convey covered works to others for the sole purpose\r\n";
	cout << "of having them make modifications exclusively for you, or provide you\r\n";
	cout << "with facilities for running those works, provided that you comply with\r\n";
	cout << "the terms of this License in conveying all material for which you do\r\n";
	cout << "not control copyright.  Those thus making or running the covered works\r\n";
	cout << "for you must do so exclusively on your behalf, under your direction\r\n";
	cout << "and control, on terms that prohibit them from making any copies of\r\n";
	cout << "your copyrighted material outside their relationship with you.\r\n";

	cout << "Conveying under any other circumstances is permitted solely under\r\n";
	cout << "the conditions stated below.  Sublicensing is not allowed; section 10\r\n";
	cout << "makes it unnecessary." << endl;
}

void flags() {

	cout << endl;
	cout << "-a\t\tenable auto-boot and reboot the device.\r\n";
	cout << "-c <arg>\tsend a command to the device.\r\n";
	cout << "-e <arg>\tupload a file and execute usb control exploit (0x21).\r\n";
	cout << "-r\t\treset the usb connection.\r\n";
	cout << "-o\t\tshow conditions of use.\r\n";
	cout << "-s\t\tstart an interactive shell with iBoot/iBSS.\r\n";
	cout << "-u <arg>\tupload a file to the device.\r\n";
	cout << "-w\t\tshow warranty information.\r\n";
	cout << "-v\t\tshow version information.\r\n";
	cout << "-h\t\tthis information." << endl << endl;
}

void shutdown() {

	Device.Disconnect();
	exit(1);
}

void warranty() {

	cout << "THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY\r\n";
	cout << "APPLICABLE LAW.  EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT\r\n";
	cout << "HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM \"AS IS\" WITHOUT WARRANTY\r\n";
	cout << "OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO,\r\n";
	cout << "THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR\r\n";
	cout << "PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM\r\n";
	cout << "IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF\r\n";
	cout << "ALL NECESSARY SERVICING, REPAIR OR CORRECTION." << endl;
}
