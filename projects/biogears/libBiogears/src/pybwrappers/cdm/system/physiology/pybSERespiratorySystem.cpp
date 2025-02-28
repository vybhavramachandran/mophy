#include <biogears/cdm/properties/SEScalar.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <biogears/cdm/properties/SEScalarAmountPerVolume.h>
#include <biogears/cdm/properties/SEScalarFlowResistance.h>
#include <biogears/cdm/properties/SEScalarFraction.h>
#include <biogears/cdm/properties/SEScalarFrequency.h>
#include <biogears/cdm/properties/SEScalarHeatCapacitancePerMass.h>
#include <biogears/cdm/properties/SEScalarMass.h>
#include <biogears/cdm/properties/SEScalarMassPerVolume.h>
#include <biogears/cdm/properties/SEScalarPower.h>
#include <biogears/cdm/properties/SEScalarPressure.h>
#include <biogears/cdm/properties/SEScalarPressureTimePerVolumeArea.h>
#include <biogears/cdm/properties/SEScalarTemperature.h>
#include <biogears/cdm/properties/SEScalarTime.h>
#include <biogears/cdm/properties/SEScalarVolume.h>
#include <biogears/cdm/properties/SEScalarVolumePerTime.h>
#include <biogears/cdm/properties/SEScalarVolumePerTimeArea.h>
#include <biogears/cdm/system/SESystem.h>
#include <biogears/cdm/properties/SEScalarFlowCompliance.h>
#include <biogears/cdm/system/physiology/SERespiratorySystem.h>
#include <biogears/cdm/utils/Logger.h>
#include <biogears/container/Tree.tci.h>
#include <biogears/exports.h>
#include <biogears/schema/biogears/BioGearsPhysiology.hxx>

#include <biogears/schema/cdm/Physiology.hxx>
// #include <biogears/biogears/schema/cdm/Properties.hxx>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pybSERespiratorySystem, m)
{
  py::module_::import("pybSESystem");

  py::class_<biogears::SERespiratorySystem, biogears::SESystem>(m, "SERespiratorySystem")
    .def(py::init<biogears::Logger*>())
    .def("GetRespirationRate", py::overload_cast<>(&biogears::SERespiratorySystem::GetRespirationRate))
    .def("GetRespirationRate", py::overload_cast<const biogears::FrequencyUnit&>(&biogears::SERespiratorySystem::GetRespirationRate, py::const_))
    .def("GetAlveolarArterialGradient", py::overload_cast<>(&biogears::SERespiratorySystem::GetAlveolarArterialGradient))
    .def("GetAlveolarArterialGradient", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetAlveolarArterialGradient, py::const_))
    .def("GetCarricoIndex", py::overload_cast<>(&biogears::SERespiratorySystem::GetCarricoIndex))
    .def("GetCarricoIndex", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetCarricoIndex, py::const_))
    .def("GetEndTidalCarbonDioxideFraction", py::overload_cast<>(&biogears::SERespiratorySystem::GetEndTidalCarbonDioxideFraction))
    .def("GetEndTidalCarbonDioxideFraction", py::overload_cast<>(&biogears::SERespiratorySystem::GetEndTidalCarbonDioxideFraction, py::const_))
    .def("GetEndTidalCarbonDioxidePressure", py::overload_cast<>(&biogears::SERespiratorySystem::GetEndTidalCarbonDioxidePressure))
    .def("GetEndTidalCarbonDioxidePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetEndTidalCarbonDioxidePressure, py::const_))
    .def("GetExpiratoryFlow", py::overload_cast<>(&biogears::SERespiratorySystem::GetExpiratoryFlow))
    .def("GetExpiratoryFlow", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetExpiratoryFlow, py::const_))
    .def("GetInspiratoryExpiratoryRatio", py::overload_cast<>(&biogears::SERespiratorySystem::GetInspiratoryExpiratoryRatio))
    .def("GetInspiratoryExpiratoryRatio", py::overload_cast<>(&biogears::SERespiratorySystem::GetInspiratoryExpiratoryRatio, py::const_))
    .def("GetInspiratoryFlow", py::overload_cast<>(&biogears::SERespiratorySystem::GetInspiratoryFlow))
    .def("GetInspiratoryFlow", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetInspiratoryFlow, py::const_))
    .def("GetMeanPleuralPressure", py::overload_cast<>(&biogears::SERespiratorySystem::GetMeanPleuralPressure))
    .def("GetMeanPleuralPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetMeanPleuralPressure, py::const_))
    .def("GetPulmonaryCompliance", py::overload_cast<>(&biogears::SERespiratorySystem::GetPulmonaryCompliance))
    .def("GetPulmonaryCompliance", py::overload_cast<const biogears::FlowComplianceUnit&>(&biogears::SERespiratorySystem::GetPulmonaryCompliance, py::const_))
    .def("GetPulmonaryResistance", py::overload_cast<>(&biogears::SERespiratorySystem::GetPulmonaryResistance))
    .def("GetPulmonaryResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERespiratorySystem::GetPulmonaryResistance, py::const_))
    .def("GetRespirationDriverFrequency", py::overload_cast<>(&biogears::SERespiratorySystem::GetRespirationDriverFrequency))
    .def("GetRespirationDriverFrequency", py::overload_cast<const biogears::FrequencyUnit&>(&biogears::SERespiratorySystem::GetRespirationDriverFrequency, py::const_))
    .def("GetRespirationDriverPressure", py::overload_cast<>(&biogears::SERespiratorySystem::GetRespirationDriverPressure))
    .def("GetRespirationDriverPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetRespirationDriverPressure, py::const_))
    .def("GetRespirationMusclePressure", py::overload_cast<>(&biogears::SERespiratorySystem::GetRespirationMusclePressure))
    .def("GetRespirationMusclePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetRespirationMusclePressure, py::const_))
    .def("GetSpecificVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetSpecificVentilation))
    .def("GetSpecificVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetSpecificVentilation, py::const_))
    .def("GetTargetPulmonaryVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetTargetPulmonaryVentilation))
    .def("GetTargetPulmonaryVentilation", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetTargetPulmonaryVentilation, py::const_))
    .def("GetTidalVolume", py::overload_cast<>(&biogears::SERespiratorySystem::GetTidalVolume))
    .def("GetTidalVolume", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SERespiratorySystem::GetTidalVolume, py::const_))
    .def("GetTotalAlveolarVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetTotalAlveolarVentilation))
    .def("GetTotalAlveolarVentilation", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetTotalAlveolarVentilation, py::const_))
    .def("GetTotalDeadSpaceVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetTotalDeadSpaceVentilation))
    .def("GetTotalDeadSpaceVentilation", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetTotalDeadSpaceVentilation, py::const_))
    .def("GetTotalPulmonaryVentilation", py::overload_cast<>(&biogears::SERespiratorySystem::GetTotalPulmonaryVentilation))
    .def("GetTotalPulmonaryVentilation", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERespiratorySystem::GetTotalPulmonaryVentilation, py::const_))
    .def("GetTotalLungVolume", py::overload_cast<>(&biogears::SERespiratorySystem::GetTotalLungVolume))
    .def("GetTotalLungVolume", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SERespiratorySystem::GetTotalLungVolume, py::const_))
    .def("GetTranspulmonaryPressure", py::overload_cast<>(&biogears::SERespiratorySystem::GetTranspulmonaryPressure))
    .def("GetTranspulmonaryPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERespiratorySystem::GetTranspulmonaryPressure, py::const_));

#ifdef VERSION_INFO
      m.attr("__version__")
    = VERSION_INFO;
#else
      m.attr("__version__")
    = "dev";
#endif
}