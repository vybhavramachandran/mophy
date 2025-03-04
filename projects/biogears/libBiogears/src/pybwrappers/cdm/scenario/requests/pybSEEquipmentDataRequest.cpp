#include <biogears/cdm/scenario/requests/SEEquipmentDataRequest.h>
#include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/cdm/scenario/requests/SEDataRequestManager.h>
#include <biogears/schema/cdm/Environment.hxx>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <string>
#include <pybind11/pybind11.h>


namespace py = pybind11;




PYBIND11_MODULE(pybSEEquipmentDataRequest, m) {


    py::class_<biogears::SEEquipmentDataRequest,biogears::SEDataRequest>(m, "SEEquipmentDataRequest")
    .def("Clear",py::overload_cast<>(&biogears::SEEquipmentDataRequest::Clear))
    .def("Load",&biogears::SEEquipmentDataRequest::Load)
    .def("Unload",py::overload_cast<>(&biogears::SEEquipmentDataRequest::Unload,py::const_))
    .def("HashCode",py::overload_cast<>(&biogears::SEEquipmentDataRequest::HashCode,py::const_))
    
    .def("GetType",&biogears::SEEquipmentDataRequest::GetType)
    .def("SetType",py::overload_cast<const char*>(&biogears::SEEquipmentDataRequest::SetType))
    .def("SetType",py::overload_cast<const std::string&>(&biogears::SEEquipmentDataRequest::SetType))
    .def("HasType",&biogears::SEEquipmentDataRequest::HasType)
    .def("InvalidateType",&biogears::SEEquipmentDataRequest::InvalidateType);


    
  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}