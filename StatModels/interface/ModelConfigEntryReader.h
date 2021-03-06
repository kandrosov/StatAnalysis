/*! Definition of the stat model configuration entry reader.
This file is part of https://github.com/cms-hh/HHStatAnalysis. */

#pragma once

#include "HHStatAnalysis/Core/interface/ConfigReader.h"
#include "StatModelDescriptor.h"

namespace hh_analysis {

class ModelConfigEntryReader : public analysis::ConfigEntryReader {
public:
    ModelConfigEntryReader(ModelDescriptorCollection& _descriptors) : descriptors(&_descriptors) {}

    virtual void StartEntry(const std::string& name, const std::string& reference_name) override
    {
        ConfigEntryReader::StartEntry(name, reference_name);
        current = StatModelDescriptor();
        current = reference_name.size() ? descriptors->at(reference_name) : StatModelDescriptor();
        current.name = name;
    }

    virtual void EndEntry() override
    {
        CheckReadParamCounts("stat_model", 1, Condition::less_equal);
        CheckReadParamCounts("channels", 1, Condition::less_equal);
        CheckReadParamCounts("categories", 1, Condition::less_equal);
        CheckReadParamCounts("signal_process", 1, Condition::less_equal);
        CheckReadParamCounts("model_signal_process", 1, Condition::less_equal);
        CheckReadParamCounts("signal_point_prefix", 1, Condition::less_equal);
        CheckReadParamCounts("signal_points", 1, Condition::less_equal);
        CheckReadParamCounts("limit_type", 1, Condition::less_equal);
        CheckReadParamCounts("th_model_file", 1, Condition::less_equal);
        CheckReadParamCounts("blind", 1, Condition::less_equal);
        CheckReadParamCounts("morph", 1, Condition::less_equal);
        CheckReadParamCounts("combine_channels", 1, Condition::less_equal);
        CheckReadParamCounts("per_channel_limits", 1, Condition::less_equal);
        CheckReadParamCounts("per_category_limits", 1, Condition::less_equal);
        CheckReadParamCounts("grid_x", 1, Condition::less_equal);
        CheckReadParamCounts("grid_y", 1, Condition::less_equal);

        (*descriptors)[current.name] = current;
    }

    virtual void ReadParameter(const std::string& /*param_name*/, const std::string& /*param_value*/,
                               std::istringstream& /*ss*/) override
    {
        ParseEntry("stat_model", current.stat_model);
        ParseEntryList("channels", current.channels);
        ParseEntryList("categories", current.categories);
        ParseEntry("signal_process", current.signal_process);
        ParseEntry("model_signal_process", current.model_signal_process);
        ParseEntry("signal_point_prefix", current.signal_point_prefix);
        ParseEntryList("signal_points", current.signal_points);
        ParseEntry("limit_type", current.limit_type);
        ParseEntry("th_model_file", current.th_model_file);
        ParseEntry("blind", current.blind);
        ParseEntry("morph", current.morph);
        ParseEntry("combine_channels", current.combine_channels);
        ParseEntry("per_channel_limits", current.per_channel_limits);
        ParseEntry("per_category_limits", current.per_category_limits);
        ParseEntry("grid_x", current.grid_x);
        ParseEntry("grid_y", current.grid_y);
        ParseEntry("custom_param", current.custom_params);
    }

private:
    StatModelDescriptor current;
    ModelDescriptorCollection* descriptors;
};

} // namespace hh_analysis
