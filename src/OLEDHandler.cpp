#include "OLEDHandler.h"

OLEDHandler::OLEDHandler(int SCL, int SDA)
{
  pinSCL=SCL;
  pinSDA=SDA;

}


OLEDHandler::~OLEDHandler()
{

}


bool OLEDHandler::init()
{

  return false;
} 

