/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// FooBar Widgets includes
#include "PerkTutorCommon.h"

// For getting the module logic
#include "qSlicerApplication.h"
#include "qSlicerModuleManager.h"
#include "qSlicerAbstractCoreModule.h"



// Matrix: 4x4 <--> Double <--> String --------------------------

std::string PerkTutorCommon
::MatrixDoubleToString( double* matrixDouble )
{
  std::stringstream ss;

  for ( int i = 0; i < 16; i++ )
  {
    ss << matrixDouble[ i ] << " ";
  }

  return ss.str();
}


void PerkTutorCommon
::MatrixStringToDouble( std::string matrixString, double* matrixDouble )
{
  std::stringstream ss( matrixString );

  for ( int i = 0; i < 16; i++ )
  {
    ss >> matrixDouble[ i ];
  }
  
}


std::string PerkTutorCommon
::Matrix4x4ToString( vtkMatrix4x4* matrix4x4 )
{
  std::stringstream ss;

  for ( int i = 0; i < 4; i++ )
  {
    for ( int j = 0; j < 4; j++ )
    {
      ss << matrix4x4->GetElement( i, j ) << " ";
    }
  }

  return ss.str();
}


void PerkTutorCommon
::MatrixStringTo4x4( std::string matrixString, vtkMatrix4x4* matrix4x4 )
{
  std::stringstream ss( matrixString );

  double value;

  for ( int i = 0; i < 4; i++ )
  {
    for ( int j = 0; j < 4; j++ )
    {
      ss >> value;
      matrix4x4->SetElement( i, j, value );
    }
  }

}


void PerkTutorCommon
::Matrix4x4ToDouble( vtkMatrix4x4* matrix4x4, double* matrixDouble )
{
  for ( int i = 0; i < 4; i++ )
  {
    for ( int j = 0; j < 4; j++ )
    {
      matrixDouble[ 4 * i + j ] = matrix4x4->GetElement( i, j );
    }
  }

}


void PerkTutorCommon
::MatrixDoubleTo4x4( double* matrixDouble, vtkMatrix4x4* matrix4x4 )
{
  for ( int i = 0; i < 4; i++ )
  {
    for ( int j = 0; j < 4; j++ )
    {
      matrix4x4->SetElement( i, j, matrixDouble[ 4 * i + j ] );
    }
  }

}



// Module logic -------------------------------------------------
vtkMRMLAbstractLogic* PerkTutorCommon
::GetSlicerModuleLogic( std::string moduleName )
{
  qSlicerAbstractCoreModule* Module = qSlicerApplication::application()->moduleManager()->module( moduleName.c_str() );
  if ( Module != NULL )
  {
    return Module->logic();
  }
  return NULL;
}