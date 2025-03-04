// #include <biogears/cdm/utils/Logger.h>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/exports.h>
#include <string>
#include <pybind11/pybind11.h>
#include <biogears/cdm/patient/actions/SEPatientAction.h>
#include <biogears/schema/cdm/PatientActions.hxx>
#include <biogears/cdm/patient/actions/SESubstanceBolus.h>
#include <biogears/cdm/patient/actions/SESubstanceAdministration.h>
#include <biogears/cdm/CommonDataModel.h>
#include <biogears/cdm/properties/SEScalarTime.h>
#include <biogears/cdm/properties/SEScalarVolume.h>
#include <biogears/cdm/properties/SEScalarMassPerVolume.h>
#include <biogears/cdm/substance/SESubstance.h>
#include <biogears/schema/cdm/Scenario.hxx>
namespace py = pybind11;




PYBIND11_MODULE(pybSESubstanceBolus, m) {


    py::class_<biogears::SESubstanceBolus, biogears::SESubstanceAdministration>(m, "SESubstanceBolus")
    .def(py::init<const biogears::SESubstance&>())
    .def("Clear",&biogears::SESubstanceBolus::Clear)
    .def("IsValid",&biogears::SESubstanceBolus::IsValid)
    .def("IsActive",&biogears::SESubstanceBolus::IsActive)
    .def("Load",&biogears::SESubstanceBolus::Load)
    .def("Unload",py::overload_cast<>(&biogears::SESubstanceBolus::Unload,py::const_))
    .def("GetAdminRoute",&biogears::SESubstanceBolus::GetAdminRoute)
    .def("SetAdminRoute",&biogears::SESubstanceBolus::SetAdminRoute)
    .def("HasAdminRoute",&biogears::SESubstanceBolus::HasAdminRoute) 
    .def("InvalidateAdminRoute",&biogears::SESubstanceBolus::InvalidateAdminRoute) 
    .def("HasAdminTime",&biogears::SESubstanceBolus::HasAdminTime) 
    .def("GetAdminTime",&biogears::SESubstanceBolus::GetAdminTime) 
    .def("HasConcentration",&biogears::SESubstanceBolus::HasConcentration) 
    .def("GetConcentration",&biogears::SESubstanceBolus::GetConcentration) 
    .def("HasDose",&biogears::SESubstanceBolus::HasDose) 
    .def("GetDose",&biogears::SESubstanceBolus::GetDose) 
    .def("GetSubstance",&biogears::SESubstanceBolus::GetSubstance) 
    .def("ToString",py::overload_cast<std::ostream&>(&biogears::SESubstanceBolus::ToString,py::const_));

   py::class_<biogears::SESubstanceBolusState>(m, "SESubstanceBolusState")
    .def(py::init<const biogears::SESubstance&>())
    .def("Load",&biogears::SESubstanceBolusState::Load)
    .def("Unload",py::overload_cast<>(&biogears::SESubstanceBolusState::Unload,py::const_))
    .def("GetElapsedTime",&biogears::SESubstanceBolusState::GetElapsedTime)
    .def("GetAdministeredDose",&biogears::SESubstanceBolusState::GetAdministeredDose);

  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}