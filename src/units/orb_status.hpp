/*
   Copyright (C) 2020 by Steve Cotton <steve@octalot.co.uk>
   Part of the Battle for Wesnoth Project https://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

#pragma once

#include "picture.hpp"

#include <memory>
#include <string>

/**
 * Corresponds to the colored orbs displayed above units' hp-bar and xp-bar.
 */
enum class orb_status {
	/** The unit still has full movement and all attacks available. */
	unmoved,
	/** All moves and possible attacks have been done. */
	moved,
	/** There are still moves and/or attacks possible, but the unit doesn't fit in the "unmoved" status. */
	partial,
	/** Belongs to a friendly side */
	allied,
	/** Belongs to a non-friendly side; normally visualised by not displaying an orb. */
	enemy
};

namespace orb_status_helper
{
/**
 * Wrapper for the various preferences::show_..._orb() methods, using the
 * enum instead of exposing a separate function for each preference.
 */
bool prefs_show_orb(orb_status os);

/**
 * Wrapper for the various preferences::unmoved_color(), moved_color(), etc
 * methods, using the enum instead of exposing a separate function for each
 * preference.
 */
std::string get_orb_color(orb_status os);

/**
 * Wrapper which will assemble the image path (including IPF for the color from get_orb_color) for a given orb.
 * Returns nullptr if prefs_show_orb returns false.
 */
std::unique_ptr<image::locator> get_orb_image(orb_status os);
} // namespace orb_status_helper
