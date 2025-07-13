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


