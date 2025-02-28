#include <biogears/cdm/patient/actions/SEPupillaryResponse.h>
#include <biogears/cdm/properties/SEScalar.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <biogears/cdm/properties/SEScalarAmountPerTime.h>
#include <biogears/cdm/properties/SEScalarAmountPerVolume.h>
#include <biogears/cdm/properties/SEScalarFlowResistance.h>
#include <biogears/cdm/properties/SEScalarFraction.h>
#include <biogears/cdm/properties/SEScalarFrequency.h>
#include <biogears/cdm/properties/SEScalarHeatCapacitancePerMass.h>
#include <biogears/cdm/properties/SEScalarMass.h>
#include <biogears/cdm/properties/SEScalarMassPerTime.h>
#include <biogears/cdm/properties/SEScalarMassPerVolume.h>
#include <biogears/cdm/properties/SEScalarPower.h>
#include <biogears/cdm/properties/SEScalarPressure.h>
#include <biogears/cdm/properties/SEScalarPressureTimePerVolumeArea.h>
#include <biogears/cdm/properties/SEScalarTemperature.h>
#include <biogears/cdm/properties/SEScalarTime.h>
#include <biogears/cdm/properties/SEScalarVolume.h>
#include <biogears/cdm/properties/SEScalarVolumePerTime.h>
#include <biogears/cdm/properties/SEScalarVolumePerTimeArea.h>
#include <biogears/cdm/substance/SESubstanceManager.h>
#include <biogears/cdm/system/SESystem.h>

#include <biogears/cdm/system/physiology/SEDrugSystem.h>
#include <biogears/cdm/utils/Logger.h>
#include <biogears/container/Tree.tci.h>
#include <biogears/exports.h>
#include <biogears/schema/biogears/BioGearsPhysiology.hxx>

#include <biogears/schema/cdm/Physiology.hxx>
// #include <biogears/biogears/schema/cdm/Properties.hxx>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pybSEDrugSystem, m)
{
  py::module_::import("pybSESystem");

  py::class_<biogears::SEDrugSystem, biogears::SESystem>(m, "SEDrugSystem")
    .def(py::init<biogears::Logger*>())
    .def("HasAntibioticActivity", &biogears::SEDrugSystem::HasAntibioticActivity)
    .def("GetAntibioticActivity", py::overload_cast<>(&biogears::SEDrugSystem::GetAntibioticActivity))
    .def("GetAntibioticActivity", py::overload_cast<>(&biogears::SEDrugSystem::GetAntibioticActivity, py::const_))
    .def("HasBronchodilationLevel",&biogears::SEDrugSystem::HasBronchodilationLevel)
    .def("GetBronchodilationLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetBronchodilationLevel))
    .def("GetBronchodilationLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetBronchodilationLevel, py::const_))
    .def("HasFeverChange",&biogears::SEDrugSystem::HasFeverChange)
    .def("GetFeverChange", py::overload_cast<>(&biogears::SEDrugSystem::GetFeverChange))
    .def("GetFeverChange", py::overload_cast<const biogears::TemperatureUnit&>(&biogears::SEDrugSystem::GetFeverChange, py::const_))
    .def("HasHeartRateChange", &biogears::SEDrugSystem::HasHeartRateChange)
    .def("GetHeartRateChange", py::overload_cast<>(&biogears::SEDrugSystem::GetHeartRateChange))
    .def("GetHeartRateChange", py::overload_cast<const biogears::FrequencyUnit&>(&biogears::SEDrugSystem::GetHeartRateChange, py::const_))
    .def("HasHemorrhageChange",&biogears::SEDrugSystem::HasHemorrhageChange)
    .def("GetHemorrhageChange", py::overload_cast<>(&biogears::SEDrugSystem::GetHemorrhageChange))
    .def("GetHemorrhageChange", py::overload_cast<>(&biogears::SEDrugSystem::GetHemorrhageChange, py::const_))
    .def("HasMeanBloodPressureChange", &biogears::SEDrugSystem::HasMeanBloodPressureChange)
    .def("GetMeanBloodPressureChange", py::overload_cast<>(&biogears::SEDrugSystem::GetMeanBloodPressureChange))
    .def("GetMeanBloodPressureChange", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEDrugSystem::GetMeanBloodPressureChange, py::const_))
    .def("HasNeuromuscularBlockLevel",&biogears::SEDrugSystem::HasNeuromuscularBlockLevel)
    .def("GetNeuromuscularBlockLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetNeuromuscularBlockLevel))
    .def("GetNeuromuscularBlockLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetNeuromuscularBlockLevel, py::const_))
    .def("HasPainToleranceChange",&biogears::SEDrugSystem::HasPainToleranceChange)
    .def("GetPainToleranceChange", py::overload_cast<>(&biogears::SEDrugSystem::GetPainToleranceChange))
    .def("GetPainToleranceChange", py::overload_cast<>(&biogears::SEDrugSystem::GetPainToleranceChange, py::const_))
    .def("HasPulsePressureChange",&biogears::SEDrugSystem::HasPulsePressureChange)
    .def("GetPulsePressureChange", py::overload_cast<>(&biogears::SEDrugSystem::GetPulsePressureChange))
    .def("GetPulsePressureChange", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEDrugSystem::GetPulsePressureChange, py::const_))
    .def("HasRespirationRateChange",&biogears::SEDrugSystem::HasRespirationRateChange)
    .def("GetRespirationRateChange", py::overload_cast<>(&biogears::SEDrugSystem::GetRespirationRateChange))
    .def("GetRespirationRateChange", py::overload_cast<const biogears::FrequencyUnit&>(&biogears::SEDrugSystem::GetRespirationRateChange, py::const_))
    .def("HasSedationLevel", &biogears::SEDrugSystem::HasSedationLevel)
    .def("GetSedationLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetSedationLevel))
    .def("GetSedationLevel", py::overload_cast<>(&biogears::SEDrugSystem::GetSedationLevel, py::const_))
    .def("HasTidalVolumeChange",&biogears::SEDrugSystem::HasTidalVolumeChange)
    .def("GetTidalVolumeChange", py::overload_cast<>(&biogears::SEDrugSystem::GetTidalVolumeChange))
    .def("GetTidalVolumeChange", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SEDrugSystem::GetTidalVolumeChange, py::const_))
    .def("HasTubularPermeabilityChange",&biogears::SEDrugSystem::HasTubularPermeabilityChange)
    .def("GetTubularPermeabilityChange", py::overload_cast<>(&biogears::SEDrugSystem::GetTubularPermeabilityChange))
    .def("GetTubularPermeabilityChange", py::overload_cast<>(&biogears::SEDrugSystem::GetTubularPermeabilityChange, py::const_))
    .def("HasCentralNervousResponse", &biogears::SEDrugSystem::HasCentralNervousResponse)
    .def("GetCentralNervousResponse", py::overload_cast<>(&biogears::SEDrugSystem::GetCentralNervousResponse))
    .def("GetTubularPermeabilityChange", py::overload_cast<>(&biogears::SEDrugSystem::GetCentralNervousResponse, py::const_));

#ifdef VERSION_INFO
      m.attr("__version__")
    = VERSION_INFO;
#else
      m.attr("__version__")
    = "dev";
#endif
}