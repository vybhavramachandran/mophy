
#include <biogears/cdm/CommonDataModel.h>
#include <biogears/exports.h>
#include <biogears/cdm/utils/Logger.h>
#include <pybind11/pybind11.h>
#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/scenario/SEScenario.h>
#include <biogears/cdm/patient/SEPatient.h>
#include <biogears/cdm/scenario/SECondition.h>
#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/engine/PhysiologyEngineConfiguration.h>
#include <biogears/cdm/scenario/SEScenarioInitialParameters.h>

#include <string>

namespace py = pybind11;

PYBIND11_MODULE(pybSEScenarioInitialParameters, m)
{

  py::class_<biogears::SEScenarioInitialParameters, biogears::Loggable, std::unique_ptr<biogears::SEScenarioInitialParameters, py::nodelete>>(m, "SEScenarioInitialParameters")
    .def("Clear", &biogears::SEScenarioInitialParameters::Clear)
    .def("Load", &biogears::SEScenarioInitialParameters::Load)
    .def("Unload", py::overload_cast<>(&biogears::SEScenarioInitialParameters::Unload,py::const_))

    .def("IsValid", &biogears::SEScenarioInitialParameters::IsValid)

    .def("GetConfiguration", py::overload_cast<>(&biogears::SEScenarioInitialParameters::GetConfiguration))
    .def("GetConfiguration", py::overload_cast<>(&biogears::SEScenarioInitialParameters::GetConfiguration,py::const_))
    .def("SetConfiguration", &biogears::SEScenarioInitialParameters::SetConfiguration)
    .def("HasConfiguration", &biogears::SEScenarioInitialParameters::HasConfiguration)
    .def("InvalidateConfiguration", &biogears::SEScenarioInitialParameters::InvalidateConfiguration)

    .def("SetPatientFile", py::overload_cast<const char*>(&biogears::SEScenarioInitialParameters::SetPatientFile))
    .def("SetPatientFile", py::overload_cast<const std::string&>(&biogears::SEScenarioInitialParameters::SetPatientFile))
    .def("GetPatientFile", &biogears::SEScenarioInitialParameters::GetPatientFile)
    .def("HasPatientFile", &biogears::SEScenarioInitialParameters::HasPatientFile)
    .def("InvalidatePatientFile", &biogears::SEScenarioInitialParameters::InvalidatePatientFile)   
  

    .def("GetPatient", py::overload_cast<>(&biogears::SEScenarioInitialParameters::GetPatient))
    .def("GetPatient", py::overload_cast<>(&biogears::SEScenarioInitialParameters::GetPatient,py::const_))
    .def("SetPatient", &biogears::SEScenarioInitialParameters::SetPatient)
    .def("HasPatient", &biogears::SEScenarioInitialParameters::HasPatient)
    .def("InvalidatePatient", &biogears::SEScenarioInitialParameters::InvalidatePatient)

    .def("AddCondition", &biogears::SEScenarioInitialParameters::AddCondition)
    .def("GetConditions", &biogears::SEScenarioInitialParameters::GetConditions)

    .def("TrackingStabilization", &biogears::SEScenarioInitialParameters::TrackingStabilization)
    .def("SetTrackStabilization", &biogears::SEScenarioInitialParameters::SetTrackStabilization);

#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}