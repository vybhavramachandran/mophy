// #include <biogears/cdm/utils/Logger.h>
// #include <biogears/cdm/substance/SESubstanceManager.h>
// #include <biogears/cdm/utils/DataTrack.h>
// #include <biogears/cdm/scenario/requests/SEDataRequest.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <string>
#include <pybind11/pybind11.h>
#include <biogears/cdm/patient/actions/SEPatientAction.h>
#include <biogears/schema/cdm/PatientActions.hxx>
#include <biogears/cdm/patient/actions/SEChestOcclusiveDressing.h>
#include <biogears/schema/cdm/Scenario.hxx>


namespace py = pybind11;




PYBIND11_MODULE(pybSEChestOcclusiveDressing, m) {


    py::class_<biogears::SEChestOcclusiveDressing>(m, "SEChestOcclusiveDressing")
    .def(py::init<>())    
    .def("TypeTag",&biogears::SEChestOcclusiveDressing::TypeTag)
    .def("classname",py::overload_cast<>(&biogears::SEChestOcclusiveDressing::classname,py::const_))
    .def("Clear",py::overload_cast<>(&biogears::SEChestOcclusiveDressing::Clear))
    .def("IsValid",py::overload_cast<>(&biogears::SEChestOcclusiveDressing::IsValid,py::const_))
    .def("IsActive",py::overload_cast<>(&biogears::SEChestOcclusiveDressing::IsActive,py::const_))
    .def("SetActive",&biogears::SEChestOcclusiveDressing::SetActive)
    .def("Load",&biogears::SEChestOcclusiveDressing::Load)
    .def("Unload",py::overload_cast<>(&biogears::SEChestOcclusiveDressing::Unload,py::const_))
    .def("GetSide",&biogears::SEChestOcclusiveDressing::GetSide)
    .def("SetSide",&biogears::SEChestOcclusiveDressing::SetSide)
    .def("HasSide",&biogears::SEChestOcclusiveDressing::HasSide)
    .def("InvalidateSide",&biogears::SEChestOcclusiveDressing::InvalidateSide)
    .def("ToString",py::overload_cast<std::ostream&>(&biogears::SEChestOcclusiveDressing::ToString,py::const_));

  
#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}