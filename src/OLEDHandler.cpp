/*
Minidisc Audio Interface
Copyright (C) 2025 Tim Myers 

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/


#include "OLEDHandler.h"

OLEDHandler::OLEDHandler(int SCL, int SDA, int Xmax, int Ymax)
{
  pinSCL=SCL;
  pinSDA=SDA;
  xMax=Xmax;
  yMax=Ymax;
  initialized=false;
}


OLEDHandler::~OLEDHandler()
{

}


bool OLEDHandler::init()
{
  if ( !initialized){throw new std::runtime_error ("Dsiplay handler not initialized");};
  bool bSuccess = false;
  
  return bSuccess;
} 

bool OLEDHandler::drawString(int x, int y, String str)
{
  if ( !initialized){throw new std::runtime_error ("Dsiplay handler not initialized");};
  bool bSuccess = false;

  return bSuccess;
}


