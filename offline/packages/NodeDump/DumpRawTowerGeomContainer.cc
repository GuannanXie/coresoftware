#include "DumpRawTowerGeomContainer.h"

#include <phool/PHIODataNode.h>

#include <g4cemc/RawTowerGeomContainer.h>

#include <string>

using namespace std;

typedef PHIODataNode<RawTowerGeomContainer> MyNode_t;

DumpRawTowerGeomContainer::DumpRawTowerGeomContainer(const string &NodeName): DumpObject(NodeName)
{
  return ;
}

int DumpRawTowerGeomContainer::process_Node(PHNode *myNode)
{
  RawTowerGeomContainer *rawtowergeom = NULL;
  MyNode_t *thisNode = static_cast <MyNode_t *> (myNode);
  if (thisNode)
    {
      rawtowergeom = thisNode->getData();
    }
  if (rawtowergeom)
    {
      *fout << "Calorimeter ID: " << rawtowergeom->get_calorimeter_id() << endl;
      *fout << "size: " << rawtowergeom->size() << endl;
      rawtowergeom->identify(*fout);
    }
  return 0;
}

