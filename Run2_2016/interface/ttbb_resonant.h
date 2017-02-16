/*! Stat model for X->hh->bbtautau.
This file is part of https://github.com/cms-hh/HHStatAnalysis. */

#pragma once

#include "ttbb.h"

namespace hh_analysis {
namespace stat_models {
namespace Run2_2016 {

class ttbb_resonant : public ttbb_base {
public:
    using ttbb_base::ttbb_base;

    virtual void CreateDatacards(const std::string& shapes_file, const std::string& output_path) override;

private:
    std::pair<std::string, std::string> ShapeNameRule(bool use_mass) const;
    void ExtractShapes(ch::CombineHarvester& combine_harvester, const std::string& shapes_file, bool is_signal) const;
};

} // namespace Run2_2016
} // namespace stat_models
} // namespace hh_analysis