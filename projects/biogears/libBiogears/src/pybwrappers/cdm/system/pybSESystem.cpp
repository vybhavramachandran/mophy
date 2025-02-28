// #include <biogears/cdm/utils/Logger.h>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <biogears/cdm/system/SESystem.h>
#include <biogears/cdm/utils/Logger.h>
#include <biogears/schema/cdm/Scenario.hxx>
#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(pybSESystem, m)
{

  py::module_::import("pybLogger");

  py::class_<biogears::SESystem, biogears::Loggable>(m, "SESystem");
  // .def(py::init<>())
  // .def("Clear",&biogears::SEPatientAction::Clear)
  // .def("IsValid",&biogears::SEPatientAction::IsValid)
  // .def("Load",&biogears::SEPatientAction::Load);
  // // .def("Unload",py::overload_cast<>(&biogears::SEPatientAction::Unload,py::const_))
  // // .def("ToString",py::overload_cast<std::ostream&>(&biogears::SEPatientAction::ToString,py::const_));

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}