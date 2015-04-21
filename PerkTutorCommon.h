/*==============================================================================

  Copyright (c) Laboratory for Percutaneous Surgery (PerkLab)
  Queen's University, Kingston, ON, Canada. All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Csaba Pinter, PerkLab, Queen's University
  and was supported through the Applied Cancer Research Unit program of Cancer Care
  Ontario with funds provided by the Ontario Ministry of Health and Long-Term Care

==============================================================================*/

#ifndef __PerkTutorCommon_h
#define __PerkTutorCommon_h

// STD includes
#include <cstdlib>
#include <string>
#include <sstream>

// VTK includes
#include "vtkMatrix4x4.h"
#include "vtkSmartPointer.h"

// Slicer includes
#include "vtkMRMLAbstractLogic.h"

// PerkTutor Common includes
#include "PerkTutorCommonExport.h"


/// \ingroup PerkTutor_PerkTutorCommon
class PERKTUTORCOMMON_EXPORT PerkTutorCommon
{
public:
  //----------------------------------------------------------------------------
  // Constant strings (std::string types for easy concatenation)
  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  // Utility functions
  //----------------------------------------------------------------------------

  // Convert between vtkMatrix4x4 <--> Double Array <--> String
  static std::string MatrixDoubleToString( double* matrixDouble );
  static void MatrixStringToDouble( std::string matrixString, double* matrixDouble );

  static void Matrix4x4ToDouble( vtkMatrix4x4* matrix4x4, double* matrixDouble );
  static void MatrixDoubleTo4x4( double* matrixDouble, vtkMatrix4x4* matrix4x4 );

  static std::string Matrix4x4ToString( vtkMatrix4x4* matrix4x4 );
  static void MatrixStringTo4x4( std::string matrixString, vtkMatrix4x4* matrix4x4 );

  // Grab module logic
  static vtkMRMLAbstractLogic* GetSlicerModuleLogic( std::string moduleName );
  
};

#endif