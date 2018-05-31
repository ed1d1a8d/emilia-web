/*
Standard
*/

/*
This include should include all current and legacy Rain library headers.

If possible, Rain functions should be provided in two versions: for pointer parameters, and for non-pointer parameters. Sometimes, copy constructors are slow, so using pointer versions of functions will be faster.

To use the libraries, all files in the Rain library directory must be added to the project (externally is fine). To include this file, either some project settings must be changed or use a relative/absolute include path. Suggestion: place Rain library directory (e.g. RainAeternum/RainLibrary3) under solution directory.
*/

#include "NetworkWSAInclude.h"
#include "GdiplusInclude.h"
#include "WindowsLAMInclude.h"
#include "RainWindow.h"

#include "AlgorithmLibraries.h"
#include "NetworkLibraries.h"
#include "UtilityLibraries.h"