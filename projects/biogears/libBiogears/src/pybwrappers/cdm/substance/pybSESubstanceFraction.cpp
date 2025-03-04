
#include <memory>

#include <biogears/cdm/CommonDataModel.h>
#include <biogears/exports.h>
#include <biogears/cdm/substance/SESubstanceFraction.h>
#include <biogears/cdm/substance/SESubstance.h>
#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/system/environment/SEEnvironmentalConditions.h>
#include <biogears/cdm/properties/SEScalarFraction.h>

#include <biogears/cdm/utils/Logger.h>

#include <pybind11/pybind11.h>

#include <string>

namespace py = pybind11;

PYBIND11_MODULE(pybSESubstanceFraction, m)
{

  py::class_<biogears::SESubstanceFraction, biogears::Loggable>(m, "SESubstanceFraction")
    .def(py::init<biogears::SESubstance&>())
    
    .def("Clear", &biogears::SESubstanceFraction::Clear)
    .def("Load", &biogears::SESubstanceFraction::Load)
    .def("Unload", py::overload_cast<>(&biogears::SESubstanceFraction::Unload, py::const_))

    .def("HasFractionAmount", &biogears::SESubstanceFraction::HasFractionAmount)

    .def("GetFractionAmount", py::overload_cast<>(&biogears::SESubstanceFraction::GetFractionAmount))
    .def("GetFractionAmount", py::overload_cast<>(&biogears::SESubstanceFraction::GetFractionAmount,py::const_))
    .def("GetSubstance", &biogears::SESubstanceFraction::GetSubstance);

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}