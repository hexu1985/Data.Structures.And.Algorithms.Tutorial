// node type used by winner tree
#pragma once

struct player
{
   int id, key;

   operator int () const {return key;}
};

