// #include <biogears/cdm/utils/Logger.h>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <string>
#include <pybind11/pybind11.h>
#include <biogears/cdm/patient/actions/SEPatientAction.h>
#include <biogears/schema/cdm/PatientActions.hxx>
#include <biogears/cdm/patient/actions/SEBreathHold.h>
#include <biogears/schema/cdm/Scenario.hxx>
#include <biogears/cdm/patient/actions/SEConsciousRespirationCommand.h>
#include <biogears/cdm/properties/SEScalarTime.h>

namespace py = pybind11;




PYBIND11_MODULE(pybSEBreathHold, m) {


    py::class_<biogears::SEBreathHold>(m, "SEBreathHold")
    .def(py::init<>())    
    // .def("TypeTag",&biogears::SEBreathHold::TypeTag)
    // .def("classname",py::overload_cast<>(&biogears::SEBreathHold::classname,py::const_))
    .def("Clear",py::overload_cast<>(&biogears::SEBreathHold::Clear))
    .def("IsValid",py::overload_cast<>(&biogears::SEBreathHold::IsValid,py::const_))
    .def("IsActive",py::overload_cast<>(&biogears::SEBreathHold::IsActive,py::const_))
    .def("Load",&biogears::SEBreathHold::Load)
    .def("Unload",py::overload_cast<>(&biogears::SEBreathHold::Unload,py::const_))
    .def("HasPeriod",&biogears::SEBreathHold::HasPeriod)
    .def("GetPeriod",&biogears::SEBreathHold::GetPeriod)
    .def("ToString",py::overload_cast<std::ostream&>(&biogears::SEBreathHold::ToString,py::const_));


    
  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}