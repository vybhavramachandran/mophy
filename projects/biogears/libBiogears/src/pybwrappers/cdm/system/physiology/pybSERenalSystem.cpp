#include <biogears/cdm/properties/SEScalar.h>
#include <biogears/cdm/properties/SEScalar0To1.h>
#include <biogears/cdm/properties/SEScalarAmountPerVolume.h>
#include <biogears/cdm/properties/SEScalarFlowCompliance.h>
#include <biogears/cdm/properties/SEScalarFlowResistance.h>
#include <biogears/cdm/properties/SEScalarFraction.h>
#include <biogears/cdm/properties/SEScalarFrequency.h>
#include <biogears/cdm/properties/SEScalarHeatCapacitancePerMass.h>
#include <biogears/cdm/properties/SEScalarMass.h>
#include <biogears/cdm/properties/SEScalarMassPerVolume.h>
#include <biogears/cdm/properties/SEScalarPower.h>
#include <biogears/cdm/properties/SEScalarPressure.h>
#include <biogears/cdm/properties/SEScalarArea.h>
#include <biogears/cdm/properties/SEScalarPressureTimePerVolumeArea.h>
#include <biogears/cdm/properties/SEScalarTemperature.h>
#include <biogears/cdm/properties/SEScalarTime.h>
#include <biogears/cdm/properties/SEScalarVolume.h>
#include <biogears/cdm/properties/SEScalarVolumePerTime.h>
#include <biogears/cdm/properties/SEScalarVolumePerTimeArea.h>
#include <biogears/cdm/properties/SEScalarVolumePerTimePressureArea.h>
#include <biogears/cdm/properties/SEScalarOsmolality.h>
#include <biogears/cdm/properties/SEScalarOsmolarity.h>
#include <biogears/cdm/system/SESystem.h>
#include <biogears/cdm/system/physiology/SERenalSystem.h>
#include <biogears/cdm/utils/Logger.h>
#include <biogears/container/Tree.tci.h>
#include <biogears/exports.h>
#include <biogears/schema/biogears/BioGearsPhysiology.hxx>

#include <biogears/schema/cdm/Physiology.hxx>
// #include <biogears/biogears/schema/cdm/Properties.hxx>
#include <pybind11/pybind11.h>

namespace py = pybind11;

PYBIND11_MODULE(pybSERenalSystem, m)
{
  py::module_::import("pybSESystem");

  py::class_<biogears::SERenalSystem, biogears::SESystem>(m, "SERenalSystem")
    .def(py::init<biogears::Logger*>())
    .def("GetGlomerularFiltrationRate", py::overload_cast<>(&biogears::SERenalSystem::GetGlomerularFiltrationRate))
    .def("GetGlomerularFiltrationRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetGlomerularFiltrationRate, py::const_))
    .def("GetFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetFiltrationFraction))
    .def("GetFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetFiltrationFraction, py::const_))
    .def("GetLeftAfferentArterioleResistance", py::overload_cast<>(&biogears::SERenalSystem::GetLeftAfferentArterioleResistance))
    .def("GetLeftAfferentArterioleResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERenalSystem::GetLeftAfferentArterioleResistance, py::const_))
    .def("GetLeftBowmansCapsulesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftBowmansCapsulesHydrostaticPressure))
    .def("GetLeftBowmansCapsulesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftBowmansCapsulesHydrostaticPressure, py::const_))
    .def("GetLeftBowmansCapsulesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftBowmansCapsulesOsmoticPressure))
    .def("GetLeftBowmansCapsulesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftBowmansCapsulesOsmoticPressure, py::const_))
    .def("GetLeftEfferentArterioleResistance", py::overload_cast<>(&biogears::SERenalSystem::GetLeftEfferentArterioleResistance))
    .def("GetLeftEfferentArterioleResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERenalSystem::GetLeftEfferentArterioleResistance, py::const_))
    .def("GetLeftGlomerularCapillariesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularCapillariesHydrostaticPressure))
    .def("GetLeftGlomerularCapillariesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftGlomerularCapillariesHydrostaticPressure, py::const_))
    .def("GetLeftGlomerularCapillariesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularCapillariesOsmoticPressure))
    .def("GetLeftGlomerularCapillariesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftGlomerularCapillariesOsmoticPressure, py::const_))
    .def("GetLeftGlomerularFiltrationCoefficient", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationCoefficient))
    .def("GetLeftGlomerularFiltrationCoefficient", py::overload_cast<const biogears::VolumePerTimePressureUnit&>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationCoefficient, py::const_))
    .def("GetLeftGlomerularFiltrationRate", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationRate))
    .def("GetLeftGlomerularFiltrationRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationRate, py::const_))
    .def("GetLeftGlomerularFiltrationSurfaceArea", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationSurfaceArea))
    .def("GetLeftGlomerularFiltrationSurfaceArea", py::overload_cast<const biogears::AreaUnit&>(&biogears::SERenalSystem::GetLeftGlomerularFiltrationSurfaceArea, py::const_))
    .def("GetLeftGlomerularFluidPermeability", py::overload_cast<>(&biogears::SERenalSystem::GetLeftGlomerularFluidPermeability))
    .def("GetLeftGlomerularFluidPermeability", py::overload_cast<const biogears::VolumePerTimePressureAreaUnit&>(&biogears::SERenalSystem::GetLeftGlomerularFluidPermeability, py::const_))
    .def("GetLeftFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetLeftFiltrationFraction))
    .def("GetLeftFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetLeftFiltrationFraction, py::const_))
    .def("GetLeftNetFiltrationPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftNetFiltrationPressure))
    .def("GetLeftNetFiltrationPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftNetFiltrationPressure, py::const_))
    .def("GetLeftNetReabsorptionPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftNetReabsorptionPressure))
    .def("GetLeftNetReabsorptionPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftNetReabsorptionPressure, py::const_))
    .def("GetLeftPeritubularCapillariesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftPeritubularCapillariesHydrostaticPressure))
    .def("GetLeftPeritubularCapillariesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftPeritubularCapillariesHydrostaticPressure, py::const_))
    .def("GetLeftPeritubularCapillariesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftPeritubularCapillariesOsmoticPressure))
    .def("GetLeftPeritubularCapillariesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftPeritubularCapillariesOsmoticPressure, py::const_))
    .def("GetLeftReabsorptionFiltrationCoefficient", py::overload_cast<>(&biogears::SERenalSystem::GetLeftReabsorptionFiltrationCoefficient))
    .def("GetLeftReabsorptionFiltrationCoefficient", py::overload_cast<const biogears::VolumePerTimePressureUnit&>(&biogears::SERenalSystem::GetLeftReabsorptionFiltrationCoefficient, py::const_))
    .def("GetLeftReabsorptionRate", py::overload_cast<>(&biogears::SERenalSystem::GetLeftReabsorptionRate))
    .def("GetLeftReabsorptionRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetLeftReabsorptionRate, py::const_))
    .def("GetLeftTubularReabsorptionFiltrationSurfaceArea", py::overload_cast<>(&biogears::SERenalSystem::GetLeftTubularReabsorptionFiltrationSurfaceArea))
    .def("GetLeftTubularReabsorptionFiltrationSurfaceArea", py::overload_cast<const biogears::AreaUnit&>(&biogears::SERenalSystem::GetLeftTubularReabsorptionFiltrationSurfaceArea, py::const_))
    .def("GetLeftTubularReabsorptionFluidPermeability", py::overload_cast<>(&biogears::SERenalSystem::GetLeftTubularReabsorptionFluidPermeability))
    .def("GetLeftTubularReabsorptionFluidPermeability", py::overload_cast<const biogears::VolumePerTimePressureAreaUnit&>(&biogears::SERenalSystem::GetLeftTubularReabsorptionFluidPermeability, py::const_))
    .def("GetLeftTubularHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftTubularHydrostaticPressure))
    .def("GetLeftTubularHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftTubularHydrostaticPressure, py::const_))
    .def("GetLeftTubularOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetLeftTubularOsmoticPressure))
    .def("GetLeftTubularOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetLeftTubularOsmoticPressure, py::const_))
    .def("GetRenalBloodFlow", py::overload_cast<>(&biogears::SERenalSystem::GetRenalBloodFlow))
    .def("GetRenalBloodFlow", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetRenalBloodFlow, py::const_))
    .def("GetRenalPlasmaFlow", py::overload_cast<>(&biogears::SERenalSystem::GetRenalPlasmaFlow))
    .def("GetRenalPlasmaFlow", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetRenalPlasmaFlow, py::const_))
    .def("GetRenalVascularResistance", py::overload_cast<>(&biogears::SERenalSystem::GetRenalVascularResistance))
    .def("GetRenalVascularResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERenalSystem::GetRenalVascularResistance, py::const_))
    .def("GetRightAfferentArterioleResistance", py::overload_cast<>(&biogears::SERenalSystem::GetRightAfferentArterioleResistance))
    .def("GetRightAfferentArterioleResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERenalSystem::GetRightAfferentArterioleResistance, py::const_))
    .def("GetRightBowmansCapsulesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightBowmansCapsulesHydrostaticPressure))
    .def("GetRightBowmansCapsulesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightBowmansCapsulesHydrostaticPressure, py::const_))
    .def("GetRightBowmansCapsulesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightBowmansCapsulesOsmoticPressure))
    .def("GetRightBowmansCapsulesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightBowmansCapsulesOsmoticPressure, py::const_))
    .def("GetRightEfferentArterioleResistance", py::overload_cast<>(&biogears::SERenalSystem::GetRightEfferentArterioleResistance))
    .def("GetRightEfferentArterioleResistance", py::overload_cast<const biogears::FlowResistanceUnit&>(&biogears::SERenalSystem::GetRightEfferentArterioleResistance, py::const_))
    .def("GetRightGlomerularCapillariesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularCapillariesHydrostaticPressure))
    .def("GetRightGlomerularCapillariesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightGlomerularCapillariesHydrostaticPressure, py::const_))
    .def("GetRightGlomerularCapillariesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularCapillariesOsmoticPressure))
    .def("GetRightGlomerularCapillariesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightGlomerularCapillariesOsmoticPressure, py::const_))
    .def("GetRightGlomerularFiltrationCoefficient", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularFiltrationCoefficient))
    .def("GetRightGlomerularFiltrationCoefficient", py::overload_cast<const biogears::VolumePerTimePressureUnit&>(&biogears::SERenalSystem::GetRightGlomerularFiltrationCoefficient, py::const_))
    .def("GetRightGlomerularFiltrationRate", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularFiltrationRate))
    .def("GetRightGlomerularFiltrationRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetRightGlomerularFiltrationRate, py::const_))
    .def("GetRightGlomerularFiltrationSurfaceArea", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularFiltrationSurfaceArea))
    .def("GetRightGlomerularFiltrationSurfaceArea", py::overload_cast<const biogears::AreaUnit&>(&biogears::SERenalSystem::GetRightGlomerularFiltrationSurfaceArea, py::const_))
    .def("GetRightGlomerularFluidPermeability", py::overload_cast<>(&biogears::SERenalSystem::GetRightGlomerularFluidPermeability))
    .def("GetRightGlomerularFluidPermeability", py::overload_cast<const biogears::VolumePerTimePressureAreaUnit&>(&biogears::SERenalSystem::GetRightGlomerularFluidPermeability, py::const_))
    .def("GetRightFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetRightFiltrationFraction))
    .def("GetRightFiltrationFraction", py::overload_cast<>(&biogears::SERenalSystem::GetRightFiltrationFraction, py::const_))
    .def("GetRightNetFiltrationPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightNetFiltrationPressure))
    .def("GetRightNetFiltrationPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightNetFiltrationPressure, py::const_))
    .def("GetRightNetReabsorptionPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightNetReabsorptionPressure))
    .def("GetRightNetReabsorptionPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightNetReabsorptionPressure, py::const_))
    .def("GetRightPeritubularCapillariesHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightPeritubularCapillariesHydrostaticPressure))
    .def("GetRightPeritubularCapillariesHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightPeritubularCapillariesHydrostaticPressure, py::const_))
    .def("GetRightPeritubularCapillariesOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightPeritubularCapillariesOsmoticPressure))
    .def("GetRightPeritubularCapillariesOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightPeritubularCapillariesOsmoticPressure, py::const_))
    .def("GetRightReabsorptionFiltrationCoefficient", py::overload_cast<>(&biogears::SERenalSystem::GetRightReabsorptionFiltrationCoefficient))
    .def("GetRightReabsorptionFiltrationCoefficient", py::overload_cast<const biogears::VolumePerTimePressureUnit&>(&biogears::SERenalSystem::GetRightReabsorptionFiltrationCoefficient, py::const_))
    .def("GetRightReabsorptionRate", py::overload_cast<>(&biogears::SERenalSystem::GetRightReabsorptionRate))
    .def("GetRightReabsorptionRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetRightReabsorptionRate, py::const_))
    .def("GetRightTubularReabsorptionFiltrationSurfaceArea", py::overload_cast<>(&biogears::SERenalSystem::GetRightTubularReabsorptionFiltrationSurfaceArea))
    .def("GetRightTubularReabsorptionFiltrationSurfaceArea", py::overload_cast<const biogears::AreaUnit&>(&biogears::SERenalSystem::GetRightTubularReabsorptionFiltrationSurfaceArea, py::const_))
    .def("GetRightTubularReabsorptionFluidPermeability", py::overload_cast<>(&biogears::SERenalSystem::GetRightTubularReabsorptionFluidPermeability))
    .def("GetRightTubularReabsorptionFluidPermeability", py::overload_cast<const biogears::VolumePerTimePressureAreaUnit&>(&biogears::SERenalSystem::GetRightTubularReabsorptionFluidPermeability, py::const_))
    .def("GetRightTubularHydrostaticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightTubularHydrostaticPressure))
    .def("GetRightTubularHydrostaticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightTubularHydrostaticPressure, py::const_))
    .def("GetRightTubularOsmoticPressure", py::overload_cast<>(&biogears::SERenalSystem::GetRightTubularOsmoticPressure))
    .def("GetRightTubularOsmoticPressure", py::overload_cast<const biogears::PressureUnit&>(&biogears::SERenalSystem::GetRightTubularOsmoticPressure, py::const_))
    .def("GetUrinationRate", py::overload_cast<>(&biogears::SERenalSystem::GetUrinationRate))
    .def("GetUrinationRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetUrinationRate, py::const_))
    .def("GetUrineOsmolality", py::overload_cast<>(&biogears::SERenalSystem::GetUrineOsmolality))
    .def("GetUrineOsmolality", py::overload_cast<const biogears::OsmolalityUnit&>(&biogears::SERenalSystem::GetUrineOsmolality, py::const_))
    .def("GetUrineOsmolarity", py::overload_cast<>(&biogears::SERenalSystem::GetUrineOsmolarity))
    .def("GetUrineOsmolarity", py::overload_cast<const biogears::OsmolarityUnit&>(&biogears::SERenalSystem::GetUrineOsmolarity, py::const_))
    .def("GetUrineProductionRate", py::overload_cast<>(&biogears::SERenalSystem::GetUrineProductionRate))
    .def("GetUrineProductionRate", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetUrineProductionRate, py::const_))
    .def("GetMeanUrineOutput", py::overload_cast<>(&biogears::SERenalSystem::GetMeanUrineOutput))
    .def("GetMeanUrineOutput", py::overload_cast<const biogears::VolumePerTimeUnit&>(&biogears::SERenalSystem::GetMeanUrineOutput, py::const_))
    .def("GetUrineSpecificGravity", py::overload_cast<>(&biogears::SERenalSystem::GetUrineSpecificGravity))
    .def("GetUrineSpecificGravity", py::overload_cast<>(&biogears::SERenalSystem::GetUrineSpecificGravity, py::const_))
    .def("GetUrineVolume", py::overload_cast<>(&biogears::SERenalSystem::GetUrineVolume))
    .def("GetUrineVolume", py::overload_cast<const biogears::VolumeUnit&>(&biogears::SERenalSystem::GetUrineVolume, py::const_))
    .def("GetUrineUreaNitrogenConcentration", py::overload_cast<>(&biogears::SERenalSystem::GetUrineUreaNitrogenConcentration))
    .def("GetUrineUreaNitrogenConcentration", py::overload_cast<const biogears::MassPerVolumeUnit&>(&biogears::SERenalSystem::GetUrineUreaNitrogenConcentration, py::const_));

#ifdef VERSION_INFO
      m.attr("__version__")
    = VERSION_INFO;
#else
      m.attr("__version__")
    = "dev";
#endif
}