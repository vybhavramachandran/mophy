#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/system/environment/actions/SEEnvironmentChange.h>
#include <biogears/cdm/system/environment/actions/SEThermalApplication.h>
#include <biogears/schema/cdm/EnvironmentActions.hxx>
#include <biogears/cdm/scenario/SEEnvironmentActionCollection.h>
#include <biogears/cdm/utils/Logger.h>
#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(pybSEEnvironmentActionCollection, m)
{

  py::class_<biogears::SEEnvironmentActionCollection, biogears::Loggable>(m, "SEEnvironmentActionCollection")
    .def(py::init<biogears::SESubstanceManager&>())
    .def("Clear", &biogears::SEEnvironmentActionCollection::Clear)
    .def("Unload", &biogears::SEEnvironmentActionCollection::Unload)
    .def("ProcessAction", py::overload_cast<const biogears::SEEnvironmentAction&>(&biogears::SEEnvironmentActionCollection::ProcessAction))
    .def("ProcessAction", py::overload_cast<const CDM::EnvironmentActionData&>(&biogears::SEEnvironmentActionCollection::ProcessAction))

    .def("HasChange", &biogears::SEEnvironmentActionCollection::HasChange)
    .def("GetChange", &biogears::SEEnvironmentActionCollection::GetChange)
    .def("RemoveChange", &biogears::SEEnvironmentActionCollection::RemoveChange)

    .def("HasThermalApplication", &biogears::SEEnvironmentActionCollection::HasThermalApplication)
    .def("GetThermalApplication", &biogears::SEEnvironmentActionCollection::GetThermalApplication)
    .def("RemoveThermalApplication", &biogears::SEEnvironmentActionCollection::RemoveThermalApplication);


#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}