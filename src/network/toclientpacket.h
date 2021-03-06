/*
Minetest
Copyright (C) 2013 celeron55, Perttu Ahola <celeron55@gmail.com>
Copyright (C) 2015 nerzhul, Loic Blot <loic.blot@unix-experience.fr>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef TOCLIENTPACKET_HEADER
#define TOCLIENTPACKET_HEADER

#include "util/numeric.h"
#include "networkprotocol.h"
#include "networkpacket.h"

class ToClientPacket: public NetworkPacket
{
public:
	ToClientPacket(u8 *data, u32 datasize, u16 peer_id);
	ToClientCommand getCommand() { return m_command; }

private:
	ToClientCommand m_command;
};

#endif
