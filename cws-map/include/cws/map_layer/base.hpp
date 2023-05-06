#pragma once

#include "cws/layer/base.hpp"
#include "cws/util.hpp"
#include "cws/map_layer.hpp"

class Layers;
class Structures;

template<Derived<Layer> T>
class MapLayerBase : public MapLayer<T> {
public:
  MapLayerBase(Dimension dimension) : MapLayer<T>(dimension) {}

  virtual void nextState(const Layers & state) = 0;
};
