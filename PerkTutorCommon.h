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

// VTK includes
#include "vtkVector.h"
#include "vtkSmartPointer.h"

// Slicer includes
#include "vtkMRMLAbstractLogic.h"

/// \ingroup PerkTutor_PerkTutorCommon
class Q_SLICER_QTMODULES_PERKTUTORCOMMON_EXPORT PerkTutorCommon
{
public:
  //----------------------------------------------------------------------------
  // Constant strings (std::string types for easy concatenation)
  //----------------------------------------------------------------------------


  //----------------------------------------------------------------------------
  // Utility functions
  //----------------------------------------------------------------------------
  static vtkMRMLAbstractLogic* GetSlicerModuleLogic( std::string moduleName );
  
};

#endif