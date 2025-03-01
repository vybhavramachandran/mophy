#include <biogears/cdm/scenario/requests/SEPatientDataRequest.h>
#include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/schema/cdm/Scenario.hxx>
#include <biogears/cdm/scenario/requests/SEDataRequestManager.h>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <string>
#include <pybind11/pybind11.h>


namespace py = pybind11;




PYBIND11_MODULE(pybSEPatientDataRequest, m) {


    py::class_<biogears::SEPatientDataRequest,biogears::SEDataRequest>(m, "SEPatientDataRequest")
    .def("Clear",&biogears::SEPatientDataRequest::Clear)
    .def("HashCode",py::overload_cast<>(&biogears::SEPatientDataRequest::HashCode,py::const_))
    .def("Load",&biogears::SEPatientDataRequest::Load)
    .def("Unload",py::overload_cast<>(&biogears::SEPatientDataRequest::Unload,py::const_));

    
  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}