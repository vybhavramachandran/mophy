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

#include <biogears/cdm/system/physiology/SEBloodChemistrySystem.h>
#include <biogears/cdm/utils/Logger.h>
#include <biogears/container/Tree.tci.h>
#include <biogears/exports.h>
#include <biogears/schema/biogears/BioGearsPhysiology.hxx>

#include <biogears/schema/cdm/Physiology.hxx>
// #include <biogears/biogears/schema/cdm/Properties.hxx>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pybSEBloodChemistrySystem, m)
{
  py::module_::import("pybSESystem");

  py::class_<biogears::SEBloodChemistrySystem, biogears::SESystem>(m, "SEBloodChemistrySystem")
    .def(py::init<biogears::Logger*>())
    .def("HasBloodDensity", &biogears::SEBloodChemistrySystem::HasBloodDensity)
    .def("GetBloodDensity", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetBloodDensity))
    .def("GetBloodDensity", py::overload_cast<const biogears::MassPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetBloodDensity, py::const_))
    .def("HasArterialBloodPH", &biogears::SEBloodChemistrySystem::HasArterialBloodPH)
    .def("GetArterialBloodPH", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialBloodPH))
    .def("GetArterialBloodPH", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialBloodPH, py::const_))
    .def("HasArterialBloodPHBaseline", &biogears::SEBloodChemistrySystem::HasArterialBloodPHBaseline)
    .def("GetArterialBloodPHBaseline", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialBloodPHBaseline))
    .def("GetArterialBloodPHBaseline", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialBloodPHBaseline, py::const_))
    .def("HasVenousBloodPH", &biogears::SEBloodChemistrySystem::HasVenousBloodPH)
    .def("GetVenousBloodPH", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVenousBloodPH))
    .def("GetVenousBloodPH", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVenousBloodPH, py::const_))

    .def("HasBloodSpecificHeat", &biogears::SEBloodChemistrySystem::HasBloodSpecificHeat)
    .def("GetBloodSpecificHeat", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetBloodSpecificHeat))
    .def("GetBloodSpecificHeat", py::overload_cast<const biogears::HeatCapacitancePerMassUnit&>(&biogears::SEBloodChemistrySystem::GetBloodSpecificHeat, py::const_))

    .def("HasBloodUreaNitrogenConcentration", &biogears::SEBloodChemistrySystem::HasBloodUreaNitrogenConcentration)
    .def("GetBloodUreaNitrogenConcentration", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetBloodUreaNitrogenConcentration))
    .def("GetBloodUreaNitrogenConcentration", py::overload_cast<const biogears::MassPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetBloodUreaNitrogenConcentration, py::const_))

    .def("HasCarbonDioxideSaturation", &biogears::SEBloodChemistrySystem::HasCarbonDioxideSaturation)
    .def("GetCarbonDioxideSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetCarbonDioxideSaturation))
    .def("GetCarbonDioxideSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetCarbonDioxideSaturation, py::const_))
    .def("HasCarbonMonoxideSaturation", &biogears::SEBloodChemistrySystem::HasCarbonMonoxideSaturation)
    .def("GetCarbonMonoxideSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetCarbonMonoxideSaturation))
    .def("GetCarbonMonoxideSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetCarbonMonoxideSaturation, py::const_))
    .def("HasHematocrit", &biogears::SEBloodChemistrySystem::HasHematocrit)
    .def("GetHematocrit", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetHematocrit))
    .def("GetHematocrit", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetHematocrit, py::const_))
    .def("HasHemoglobinContent", &biogears::SEBloodChemistrySystem::HasHemoglobinContent)
    .def("GetHemoglobinContent", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetHemoglobinContent))
    .def("GetHemoglobinContent", py::overload_cast<const biogears::MassUnit&>(&biogears::SEBloodChemistrySystem::GetHemoglobinContent, py::const_))
    .def("HasHemoglobinLostToUrine", &biogears::SEBloodChemistrySystem::HasHemoglobinLostToUrine)
    .def("GetHemoglobinLostToUrine", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetHemoglobinLostToUrine))
    .def("GetHemoglobinLostToUrine", py::overload_cast<const biogears::MassUnit&>(&biogears::SEBloodChemistrySystem::GetHemoglobinLostToUrine, py::const_))
    .def("HasOxygenSaturation", &biogears::SEBloodChemistrySystem::HasOxygenSaturation)
    .def("GetOxygenSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetOxygenSaturation))
    .def("GetOxygenSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetOxygenSaturation, py::const_))
    .def("HasOxygenVenousSaturation", &biogears::SEBloodChemistrySystem::HasOxygenVenousSaturation)
    .def("GetOxygenVenousSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetOxygenVenousSaturation))
    .def("GetOxygenVenousSaturation", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetOxygenVenousSaturation, py::const_))
    .def("HasPhosphate", &biogears::SEBloodChemistrySystem::HasPhosphate)
    .def("GetPhosphate", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPhosphate))
    .def("GetPhosphate", py::overload_cast<const biogears::AmountPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetPhosphate, py::const_))
    .def("HasPlasmaVolume", &biogears::SEBloodChemistrySystem::HasPlasmaVolume)
    .def("GetPlasmaVolume", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPlasmaVolume))
    .def("GetPlasmaVolume", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SEBloodChemistrySystem::GetPlasmaVolume, py::const_))
    .def("HasPulseOximetry", &biogears::SEBloodChemistrySystem::HasPulseOximetry)
    .def("GetPulseOximetry", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulseOximetry))
    .def("GetPulseOximetry", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulseOximetry, py::const_))
    .def("HasRedBloodCellAcetylcholinesterase", &biogears::SEBloodChemistrySystem::HasRedBloodCellAcetylcholinesterase)
    .def("GetRedBloodCellAcetylcholinesterase", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetRedBloodCellAcetylcholinesterase))
    .def("GetRedBloodCellAcetylcholinesterase", py::overload_cast<const biogears::AmountPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetRedBloodCellAcetylcholinesterase, py::const_))
    .def("HasRedBloodCellCount", &biogears::SEBloodChemistrySystem::HasRedBloodCellCount)
    .def("GetRedBloodCellCount", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetRedBloodCellCount))
    .def("GetRedBloodCellCount", py::overload_cast<const biogears::AmountPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetRedBloodCellCount, py::const_))
    .def("HasStrongIonDifference", &biogears::SEBloodChemistrySystem::HasStrongIonDifference)
    .def("GetStrongIonDifference", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetStrongIonDifference))
    .def("GetStrongIonDifference", py::overload_cast<const biogears::AmountPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetStrongIonDifference, py::const_))
    .def("HasShuntFraction", &biogears::SEBloodChemistrySystem::HasShuntFraction)
    .def("GetShuntFraction", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetShuntFraction))
    .def("GetShuntFraction", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetShuntFraction, py::const_))
    .def("HasTotalBilirubin", &biogears::SEBloodChemistrySystem::HasTotalBilirubin)
    .def("GetTotalBilirubin", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetTotalBilirubin))
    .def("GetTotalBilirubin", py::overload_cast<const biogears::MassPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetTotalBilirubin, py::const_))
    .def("HasTotalProteinConcentration", &biogears::SEBloodChemistrySystem::HasTotalProteinConcentration)
    .def("GetTotalProteinConcentration", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetTotalProteinConcentration))
    .def("GetTotalProteinConcentration", py::overload_cast<const biogears::MassPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetTotalProteinConcentration, py::const_))
    .def("HasRhTransfusionReactionVolume", &biogears::SEBloodChemistrySystem::HasRhTransfusionReactionVolume)
    .def("GetRhTransfusionReactionVolume", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetRhTransfusionReactionVolume))
    .def("GetRhTransfusionReactionVolume", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SEBloodChemistrySystem::GetRhTransfusionReactionVolume, py::const_))
    .def("HasVolumeFractionNeutralPhospholipidInPlasma", &biogears::SEBloodChemistrySystem::HasVolumeFractionNeutralPhospholipidInPlasma)
    .def("GetVolumeFractionNeutralPhospholipidInPlasma", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVolumeFractionNeutralPhospholipidInPlasma))
    .def("GetVolumeFractionNeutralPhospholipidInPlasma", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVolumeFractionNeutralPhospholipidInPlasma, py::const_))
    .def("HasVolumeFractionNeutralLipidInPlasma", &biogears::SEBloodChemistrySystem::HasVolumeFractionNeutralLipidInPlasma)
    .def("GetVolumeFractionNeutralLipidInPlasma", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVolumeFractionNeutralLipidInPlasma))
    .def("GetVolumeFractionNeutralLipidInPlasma", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVolumeFractionNeutralLipidInPlasma, py::const_))
    .def("HasWhiteBloodCellCount", &biogears::SEBloodChemistrySystem::HasWhiteBloodCellCount)
    .def("GetWhiteBloodCellCount", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetWhiteBloodCellCount))
    .def("GetWhiteBloodCellCount", py::overload_cast<const biogears::AmountPerVolumeUnit&>(&biogears::SEBloodChemistrySystem::GetWhiteBloodCellCount, py::const_))
    .def("HasArterialCarbonDioxidePressure", &biogears::SEBloodChemistrySystem::HasArterialCarbonDioxidePressure)
    .def("GetArterialCarbonDioxidePressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialCarbonDioxidePressure))
    .def("GetArterialCarbonDioxidePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetArterialCarbonDioxidePressure, py::const_))
    .def("HasArterialOxygenPressure", &biogears::SEBloodChemistrySystem::HasArterialOxygenPressure)
    .def("GetArterialOxygenPressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetArterialOxygenPressure))
    .def("GetArterialOxygenPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetArterialOxygenPressure, py::const_))
    .def("HasPulmonaryArterialCarbonDioxidePressure", &biogears::SEBloodChemistrySystem::HasPulmonaryArterialCarbonDioxidePressure)
    .def("GetPulmonaryArterialCarbonDioxidePressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulmonaryArterialCarbonDioxidePressure))
    .def("GetPulmonaryArterialCarbonDioxidePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetPulmonaryArterialCarbonDioxidePressure, py::const_))
    .def("HasPulmonaryArterialOxygenPressure", &biogears::SEBloodChemistrySystem::HasPulmonaryArterialOxygenPressure)
    .def("GetPulmonaryArterialOxygenPressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulmonaryArterialOxygenPressure))
    .def("GetPulmonaryArterialOxygenPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetPulmonaryArterialOxygenPressure, py::const_))
    .def("HasPulmonaryVenousCarbonDioxidePressure", &biogears::SEBloodChemistrySystem::HasPulmonaryVenousCarbonDioxidePressure)
    .def("GetPulmonaryVenousCarbonDioxidePressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulmonaryVenousCarbonDioxidePressure))
    .def("GetPulmonaryVenousCarbonDioxidePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetPulmonaryVenousCarbonDioxidePressure, py::const_))
    .def("HasPulmonaryVenousOxygenPressure", &biogears::SEBloodChemistrySystem::HasPulmonaryVenousOxygenPressure)
    .def("GetPulmonaryVenousOxygenPressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetPulmonaryVenousOxygenPressure))
    .def("GetPulmonaryVenousOxygenPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetPulmonaryVenousOxygenPressure, py::const_))
    .def("HasVenousCarbonDioxidePressure", &biogears::SEBloodChemistrySystem::HasVenousCarbonDioxidePressure)
    .def("GetVenousCarbonDioxidePressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVenousCarbonDioxidePressure))
    .def("GetVenousCarbonDioxidePressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetVenousCarbonDioxidePressure, py::const_))
    .def("HasVenousOxygenPressure", &biogears::SEBloodChemistrySystem::HasVenousOxygenPressure)
    .def("GetVenousOxygenPressure", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetVenousOxygenPressure))
    .def("GetVenousOxygenPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SEBloodChemistrySystem::GetVenousOxygenPressure, py::const_))
    .def("HasInflammatoryResponse", &biogears::SEBloodChemistrySystem::HasInflammatoryResponse)
    .def("GetInflammatoryResponse", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetInflammatoryResponse))
    .def("GetInflammatoryResponse", py::overload_cast<>(&biogears::SEBloodChemistrySystem::GetInflammatoryResponse, py::const_));



  py::class_<biogears::SEInflammatoryResponse>(m, "SEInflammatoryResponse")
    .def(py::init<>())
    .def("HasLocalPathogen", &biogears::SEInflammatoryResponse::HasLocalPathogen)
    .def("GetLocalPathogen", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalPathogen))
    .def("GetLocalPathogen", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalPathogen, py::const_))
    .def("HasLocalBarrier", &biogears::SEInflammatoryResponse::HasLocalBarrier)
    .def("GetLocalBarrier", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalBarrier))
    .def("GetLocalBarrier", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalBarrier, py::const_))
    .def("HasLocalMacrophage", &biogears::SEInflammatoryResponse::HasLocalMacrophage)
    .def("GetLocalMacrophage", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalMacrophage))
    .def("GetLocalMacrophage", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalMacrophage, py::const_))
    .def("HasLocalNeutrophil", &biogears::SEInflammatoryResponse::HasLocalNeutrophil)
    .def("GetLocalNeutrophil", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalNeutrophil))
    .def("GetLocalNeutrophil", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetLocalNeutrophil, py::const_))
    .def("HasActiveTLR", &biogears::SEInflammatoryResponse::HasActiveTLR)
    .def("GetActiveTLR", &biogears::SEInflammatoryResponse::GetActiveTLR)

    .def("SetActiveTLR", &biogears::SEInflammatoryResponse::SetActiveTLR)
    .def("HasAutonomicResponseLevel", &biogears::SEInflammatoryResponse::HasAutonomicResponseLevel)
    .def("GetAutonomicResponseLevel", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetAutonomicResponseLevel))
    .def("GetAutonomicResponseLevel", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetAutonomicResponseLevel, py::const_))
    .def("HasCatecholamines", &biogears::SEInflammatoryResponse::HasCatecholamines)
    .def("GetCatecholamines", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetCatecholamines))
    .def("GetCatecholamines", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetCatecholamines, py::const_))
    .def("HasConstitutiveNOS", &biogears::SEInflammatoryResponse::HasConstitutiveNOS)
    .def("GetConstitutiveNOS", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetConstitutiveNOS))
    .def("GetConstitutiveNOS", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetConstitutiveNOS, py::const_))
    .def("HasInducibleNOSPre", &biogears::SEInflammatoryResponse::HasInducibleNOSPre)
    .def("GetInducibleNOSPre", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInducibleNOSPre))
    .def("GetInducibleNOSPre", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInducibleNOSPre, py::const_))
    .def("HasInducibleNOS", &biogears::SEInflammatoryResponse::HasInducibleNOS)
    .def("GetInducibleNOS", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInducibleNOS))
    .def("GetInducibleNOS", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInducibleNOS, py::const_))
    .def("HasInterleukin6", &biogears::SEInflammatoryResponse::HasInterleukin6)
    .def("GetInterleukin6", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin6))
    .def("GetInterleukin6", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin6, py::const_))
    .def("HasInterleukin10", &biogears::SEInflammatoryResponse::HasInterleukin10)
    .def("GetInterleukin10", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin10))
    .def("GetInterleukin10", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin10, py::const_))
    .def("HasInterleukin12", &biogears::SEInflammatoryResponse::HasInterleukin12)
    .def("GetInterleukin12", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin12))
    .def("GetInterleukin12", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInterleukin12, py::const_))
    .def("HasMacrophageResting", &biogears::SEInflammatoryResponse::HasMacrophageResting)
    .def("GetMacrophageResting", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetMacrophageResting))
    .def("GetMacrophageResting", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetMacrophageResting, py::const_))
    .def("HasMacrophageActive", &biogears::SEInflammatoryResponse::HasMacrophageActive)
    .def("GetMacrophageActive", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetMacrophageActive))
    .def("GetMacrophageActive", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetMacrophageActive, py::const_))
    .def("HasNeutrophilResting", &biogears::SEInflammatoryResponse::HasNeutrophilResting)
    .def("GetNeutrophilResting", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNeutrophilResting))
    .def("GetNeutrophilResting", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNeutrophilResting, py::const_))
    .def("HasNeutrophilActive", &biogears::SEInflammatoryResponse::HasNeutrophilActive)
    .def("GetNeutrophilActive", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNeutrophilActive))
    .def("GetNeutrophilActive", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNeutrophilActive, py::const_))
    .def("HasNitrate", &biogears::SEInflammatoryResponse::HasNitrate)
    .def("GetNitrate", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNitrate))
    .def("GetNitrate", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNitrate, py::const_))
    .def("HasNitricOxide", &biogears::SEInflammatoryResponse::HasNitricOxide)
    .def("GetNitricOxide", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNitricOxide))
    .def("GetNitricOxide", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetNitricOxide, py::const_))
    .def("HasBloodPathogen", &biogears::SEInflammatoryResponse::HasBloodPathogen)
    .def("GetBloodPathogen", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetBloodPathogen))
    .def("GetBloodPathogen", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetBloodPathogen, py::const_))
    .def("HasTissueIntegrity", &biogears::SEInflammatoryResponse::HasTissueIntegrity)
    .def("GetTissueIntegrity", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTissueIntegrity))
    .def("GetTissueIntegrity", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTissueIntegrity, py::const_))
    .def("HasTrauma", &biogears::SEInflammatoryResponse::HasTrauma)
    .def("GetTrauma", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTrauma))
    .def("GetTrauma", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTrauma, py::const_))
    .def("HasTumorNecrosisFactor", &biogears::SEInflammatoryResponse::HasTumorNecrosisFactor)
    .def("GetTumorNecrosisFactor", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTumorNecrosisFactor))
    .def("GetTumorNecrosisFactor", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetTumorNecrosisFactor, py::const_))
    .def("HasInflammationTime", &biogears::SEInflammatoryResponse::HasInflammationTime)
    .def("GetInflammationTime", py::overload_cast<>(&biogears::SEInflammatoryResponse::GetInflammationTime))
    .def("GetInflammationTime", py::overload_cast<const biogears::TimeUnit&>(&biogears::SEInflammatoryResponse::GetInflammationTime, py::const_))
    .def("HasInflammationSources", &biogears::SEInflammatoryResponse::HasInflammationSources)
    .def("GetInflammationSources", &biogears::SEInflammatoryResponse::GetInflammationSources)
    .def("HasInflammationSource", &biogears::SEInflammatoryResponse::HasInflammationSource)
    .def("GetPhysiologyRequestGraph", &biogears::SEInflammatoryResponse::GetPhysiologyRequestGraph);









#ifdef VERSION_INFO
      m.attr("__version__")
    = VERSION_INFO;
#else
      m.attr("__version__")
    = "dev";
#endif
}