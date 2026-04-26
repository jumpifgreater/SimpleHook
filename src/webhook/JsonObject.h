#pragma once
#include <string>
#include <unordered_map>
#include <vector>

class JSONObject
{
public:
    void put(std::string key, std::string value)
    {
        if (!value.empty())
            map[key] = "\"" + value + "\"";
    }

    void put(std::string key, int value)
    {
        map[key] = std::to_string(value);
    }

    void put(std::string key, bool value)
    {
        map[key] = value ? "true" : "false";
    }

    void put(std::string key, JSONObject value)
    {
        map[key] = value.toString();
    }

    template <typename T>
    void put(std::string key, std::vector<T> value)
    {
        std::string builder = "[";
        for (size_t i = 0; i < value.size(); i++)
        {
            builder += toString(value[i]);
            if (i != value.size() - 1)
                builder += ",";
        }
        builder += "]";
        map[key] = builder;
    }

    std::string toString()
    {
        std::string builder = "{";
        size_t i = 0;

        for (auto& entry : map)
        {
            builder += "\"" + entry.first + "\":" + entry.second;
            if (++i != map.size())
                builder += ",";
        }

        builder += "}";
        return builder;
    }

private:
    std::unordered_map<std::string, std::string> map;

    std::string toString(int value)
    {
        return std::to_string(value);
    }

    std::string toString(double value)
    {
        return std::to_string(value);
    }

    std::string toString(bool value)
    {
        return value ? "true" : "false";
    }

    std::string toString(std::string value)
    {
        return "\"" + value + "\"";
    }

    std::string toString(const char* value)
    {
        return "\"" + std::string(value) + "\"";
    }

    template <typename T>
    std::string toString(std::vector<T> value)
    {
        std::string builder = "[";
        for (size_t i = 0; i < value.size(); i++)
        {
            builder += toString(value[i]); 
            if (i != value.size() - 1)
                builder += ",";
        }
        builder += "]";
        return builder;
    }

    template <typename T>
    std::string toString(T value)
    {
        return value.toString();
    }
};