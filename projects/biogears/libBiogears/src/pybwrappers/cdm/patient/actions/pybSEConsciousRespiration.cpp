// #include <biogears/cdm/utils/Logger.h>
#include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
// #include <biogears/cdm/properties/SEScalar0To1.h>

#include <string>
#include <pybind11/pybind11.h>
#include <biogears/cdm/patient/actions/SEPatientAction.h>
#include <biogears/schema/cdm/PatientActions.hxx>
#include <biogears/cdm/patient/actions/SEConsciousRespiration.h>
#include <biogears/schema/cdm/Scenario.hxx>
#include <biogears/cdm/patient/actions/SEForcedExhale.h>
#include <biogears/cdm/patient/actions/SEForcedInhale.h>
#include <biogears/cdm/patient/actions/SEBreathHold.h>
#include <biogears/cdm/patient/actions/SEUseInhaler.h>
#include <biogears/cdm/patient/actions/SEConsciousRespirationCommand.h>
namespace py = pybind11;




PYBIND11_MODULE(pybSEConsciousRespiration, m) {


    py::class_<biogears::SEConsciousRespiration>(m, "SEChestOcclusiveDressing")
    .def(py::init<>())    
    .def("TypeTag",&biogears::SEConsciousRespiration::TypeTag)
    .def("classname",py::overload_cast<>(&biogears::SEConsciousRespiration::classname,py::const_))
    .def("Clear",py::overload_cast<>(&biogears::SEConsciousRespiration::Clear))
    .def("IsValid",py::overload_cast<>(&biogears::SEConsciousRespiration::IsValid,py::const_))
    .def("IsActive",py::overload_cast<>(&biogears::SEConsciousRespiration::IsActive,py::const_))
    // .def("SetActive",&biogears::SEConsciousRespiration::SetActive)
    .def("Load",&biogears::SEConsciousRespiration::Load)
    .def("Unload",py::overload_cast<>(&biogears::SEConsciousRespiration::Unload,py::const_))
    .def("GetActiveCommand",&biogears::SEConsciousRespiration::GetActiveCommand)
    .def("RemoveActiveCommand",&biogears::SEConsciousRespiration::RemoveActiveCommand)
    .def("AddForcedExhale",&biogears::SEConsciousRespiration::AddForcedExhale)
    .def("AddForcedInhale",&biogears::SEConsciousRespiration::AddForcedInhale)
    .def("AddBreathHold",&biogears::SEConsciousRespiration::AddBreathHold)
    .def("AddUseInhaler",&biogears::SEConsciousRespiration::AddUseInhaler)
 
    .def("ToString",py::overload_cast<std::ostream&>(&biogears::SEConsciousRespiration::ToString,py::const_));

  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}