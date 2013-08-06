/* ASEPRITE
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_UNDOERS_SET_PALETTE_COLORS_H_INCLUDED
#define APP_UNDOERS_SET_PALETTE_COLORS_H_INCLUDED

#include "app/undoers/undoer_base.h"
#include "raster/frame_number.h"
#include "undo/object_id.h"

#include <sstream>

namespace raster {
  class Palette;
  class Sprite;
}

namespace app {
  namespace undoers {
    using namespace raster;
    using namespace undo;

    class SetPaletteColors : public UndoerBase {
    public:
      SetPaletteColors(ObjectsContainer* objects, Sprite* sprite, Palette* palette, FrameNumber frame, int from, int to);

      void dispose() OVERRIDE;
      size_t getMemSize() const OVERRIDE { return sizeof(*this) + getStreamSize(); }
      void revert(ObjectsContainer* objects, UndoersCollector* redoers) OVERRIDE;

    private:
      size_t getStreamSize() const {
        return const_cast<std::stringstream*>(&m_stream)->tellp();
      }

      ObjectId m_spriteId;
      FrameNumber m_frame;
      uint8_t m_from;
      uint8_t m_to;
      std::stringstream m_stream;
    };

  } // namespace undoers
} // namespace app

#endif  // UNDOERS_SET_PALETTE_COLORS_H_INCLUDED
