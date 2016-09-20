/*PGR-GNU*****************************************************************
File: ch_edge.cpp

Generated with Template by:
Copyright (c) 2015 pgRouting developers
Mail: project@pgrouting.org

Function's developer: 
Copyright (c) 2016 Rohith Reddy
Mail: 

------

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

 ********************************************************************PGR-GNU*/

#include "./ch_edge.h"

namespace pgrouting {

void CH_edge::cp_members(const CH_edge &other, std::ostringstream& log) {
        log << "Copying members of edge\n";
        log << other;
        #if 0
        this->cost = other.cost;
        log << "after copying cost of edge\n";
        log << *this;
        this->first = other.first;
        log << "after copying first of edge\n";
        log << *this;
        this->source = other.source;
        log << "after copying source of edge\n";
        log << *this;
        this->target = other.target;
        log << "after copying target of edge\n";
        log << *this;
        this->m_contracted_vertices += other.contracted_vertices();
        log << "after adding contracted vertices\n";
        log << *this;
        #endif
        this->cost = other.cost;
        this->id = other.id;
        this->first = other.first;
        this->source = other.source;
        this->target = other.target;
        this->m_contracted_vertices += other.contracted_vertices();
        #if 0
        log << "copying eid: " << other.id << "\n";
        this->id = other.id;
        // log << "after copying id of edge\n";
        log << *this;
        #endif
    }


void CH_edge::cp_members(const CH_edge &other) {
        this->cost = other.cost;
        this->id = other.id;
        this->first = other.first;
        this->source = other.source;
        this->target = other.target;
        this->m_contracted_vertices += other.contracted_vertices();
    }

void CH_edge::cp_members(const Basic_edge &other) {
        this->id = other.id;
        this->cost = other.cost;
        this->first = other.first;
    }
bool CH_edge::has_contracted_vertices() const {
    if (m_contracted_vertices.size() == 0)
        return false;
    return true;
}

const Identifiers<int64_t>& CH_edge::contracted_vertices() const {
    return m_contracted_vertices;
}


void CH_edge::add_contracted_vertex(CH_vertex& v, int64_t vid) {
    m_contracted_vertices += vid;
    m_contracted_vertices += v.contracted_vertices();
    v.clear_contracted_vertices();
}

void CH_edge::add_contracted_edge_vertices(CH_edge &e) {
    m_contracted_vertices += e.contracted_vertices();
    e.clear_contracted_vertices();
}

std::ostream& operator <<(std::ostream& os, const CH_edge& e) {
    os << "{\n    id: " << e.id << ",\n";
    os << "    source: " << e.source << ",\n";
    os << "    target: " << e.target << ",\n";
    os << "    cost: " << e.cost << ",\n";
    os << "    first: " << e.first << ",\n";
    os << "    contracted vertices: ";
    os << e.contracted_vertices();
    os << "\n}";
    os << "\n";
    return os;
}

}  // namespace pgrouting
