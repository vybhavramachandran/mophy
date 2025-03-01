
#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/system/equipment/Inhaler/SEInhaler.h>
#include <biogears/cdm/system/equipment/Inhaler/actions/SEInhalerConfiguration.h>
#include <biogears/cdm/scenario/SEInhalerActionCollection.h>
#include <biogears/cdm/utils/Logger.h>
#include <pybind11/pybind11.h>
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(pybSEInhalerActionCollection, m)
{

  py::class_<biogears::SEInhalerActionCollection, biogears::Loggable>(m, "SEInhalerActionCollection")
    .def(py::init<biogears::SESubstanceManager&>())
    .def("Clear", &biogears::SEInhalerActionCollection::Clear)
    .def("Unload", &biogears::SEInhalerActionCollection::Unload)
    .def("ProcessAction", py::overload_cast<const biogears::SEInhalerAction&>(&biogears::SEInhalerActionCollection::ProcessAction))
    .def("ProcessAction", py::overload_cast<const CDM::InhalerActionData&>(&biogears::SEInhalerActionCollection::ProcessAction))

    .def("HasConfiguration", &biogears::SEInhalerActionCollection::HasConfiguration)
    .def("GetConfiguration", &biogears::SEInhalerActionCollection::GetConfiguration)
    .def("RemoveConfiguration", &biogears::SEInhalerActionCollection::RemoveConfiguration);


#ifdef VERSION_INFO
  m.attr("__version__") = VERSION_INFO;
#else
  m.attr("__version__") = "dev";
#endif
}