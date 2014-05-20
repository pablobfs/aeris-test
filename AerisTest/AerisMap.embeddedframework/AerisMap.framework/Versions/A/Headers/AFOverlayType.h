//
//  AFOverlayType.h
//  AerisMap
//	$Id$
//
//  Created by Nicholas Shipes on 6/25/12.
//  Copyright (c) 2012 HAMweather, LLC. All rights reserved.
//


typedef enum {
	AFOverlayTypeNone = 0,
	
	// tile overlays
	AFOverlayTypeRadar,
	AFOverlayTypeNexradRadar,
	AFOverlayTypeSatellite,
	AFOverlayTypeSatelliteVisible,
	AFOverlayTypeSatelliteGlobal,
	AFOverlayTypeAdvisory,
	AFOverlayTypeSnowDepth,
	AFOverlayTypeCurrentTemperatures,
	AFOverlayTypeCurrentWinds,
	AFOverlayTypeCurrentDewPoint,
	AFOverlayTypeCurrentHumidity,
	AFOverlayTypeCurrentWindChill,
	AFOverlayTypeCurrentHeatIndex,
	AFOverlayTypeCurrentChlorophyll,
	AFOverlayTypeCurrentSeaSurfaceTemperatures,
	
	// polygon overlays
	AFOverlayTypeWarning,
	
	// point data overlays
	AFOverlayTypeObservation,
	AFOverlayTypeRiver,
	AFOverlayTypeTide,
	AFOverlayTypeBuoy,
	AFOverlayTypeStormCell,
	AFOverlayTypeStormReport,
	AFOverlayTypeFire,
	AFOverlayTypeLightningStrike,
	AFOverlayTypeRecord,
	AFOverlayTypeEarthquake
	
} AFOverlayType;

#define kAFOverlayTypeCodesArray @"", @"radar", @"nexrad", @"sat", @"sat_visible", @"sat_global", @"alerts", @"snowdepth", @"current_temps", @"current_winds", @"current_dewpoint", @"current_humidity", @"current_windchill", @"current_heatindex", @"current_chlorophyll", @"current_sst", @"warnings", @"obs", @"river", @"tides", @"buoys", @"stormcells", @"stormreports", @"fires", @"lightning", @"records", @"earthquakes", nil

#define kAFOverlayDataCodesArray @"", @"radar", @"", @"sat", @"sat_vistrans", @"globalsat", @"alerts", @"snowdepth_snodas", @"current_2mt_toi", @"current_winds", @"current_dp", @"current_rh", @"current_windchill", @"current_heat_index", @"modis_chlo_14day", @"modis_sst_14day", nil