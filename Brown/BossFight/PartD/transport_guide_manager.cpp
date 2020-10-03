#include "transport_guide_manager.h"

#include <sstream>
#include <string>
#include <string_view>

void TransportGuideManager::PerformQueries(std::istream& input,
                                           std::ostream& output)
{
    input.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    const auto json_input = Json::Load(input).GetRoot();

    perform_read_queries(json_input.AsMap().at("base_requests").AsArray());

    routes_database_.BuildAllRoutes(stops_database_);

    perform_write_queries(json_input.AsMap().at("stat_requests").AsArray(), output);
}


void TransportGuideManager::perform_read_queries(
        const std::vector<Json::Node>& post_requests)
{
    for (const auto& request : post_requests)
    {
        if (request.AsMap().at("type").AsString() == "Stop")
        {
            BusStop stop;

            stop.name = request.AsMap().at("name").AsString();

            stop.coordinate = GroundPoint(request.AsMap().at("latitude").AsDouble(),
                                          request.AsMap().at("longitude").AsDouble());

            for (const auto& pair : request.AsMap().at("road_distances").AsMap())
            {
                stop.distance_to_other_stops[pair.first] = pair.second.AsInt();
            }

            AddStop(stop);
        }

        if (request.AsMap().at("type").AsString() == "Bus")
        {
            std::shared_ptr<IRouteInfo> route_info;
            std::string bus_name = request.AsMap().at("name").AsString();

            if (request.AsMap().at("is_roundtrip").AsBool())
            {
                route_info = std::make_shared<RoundRoute>();
            }
            else
            {
                route_info = std::make_shared<DirectRoute>();
            }

            for (const auto& stop : request.AsMap().at("stops").AsArray())
            {
                route_info->AddStop(stop.AsString());
            }

            AddRoute(bus_name, route_info);
        }
    }
}


void TransportGuideManager::perform_write_queries(
        const std::vector<Json::Node>& get_requests, std::ostream& output) const
{
    using namespace Json;

    std::vector<std::shared_ptr<JsonWriter>> result;

    for (const auto& request : get_requests)
    {
        std::map<std::string, std::shared_ptr<JsonWriter>> response;
        response["request_id"] =
                std::make_shared<JsonInt>(request.AsMap().at("id").AsInt());

        if(request.AsMap().at("type").AsString() == "Bus")
        {
            const auto route_response = routes_database_.GetRouteStats(
                    request.AsMap().at("name").AsString());

            if (route_response.second)
            {
                response["route_length"] =
                        std::make_shared<JsonInt>(route_response.second->route_length);
                response["curvature"] =
                        std::make_shared<JsonDouble>(route_response.second->curvature);
                response["stop_count"] =
                        std::make_shared<JsonInt>(route_response.second->stops_on_route);
                response["unique_stop_count"] =
                        std::make_shared<JsonInt>(route_response.second->unique_stops);
            }
            else
            {
                response["error_message"] =
                        std::make_shared<JsonString>(std::string("not found"));
            }
        }

        if (request.AsMap().at("type").AsString() == "Stop")
        {
            const auto stop_response = stops_database_.GetBusStopStat(
                    request.AsMap().at("name").AsString());

            if (stop_response.second)
            {
                std::vector<std::shared_ptr<JsonWriter>> buses;
                buses.reserve(stop_response.second->size());

                for (const auto& bus : *stop_response.second)
                {
                    buses.push_back(
                            std::make_shared<JsonString>(bus));
                }

                response["buses"] = std::make_shared<JsonArray>(buses);
            }
            else
            {
                response["error_message"] =
                        std::make_shared<JsonString>(std::string("not found"));
            }
        }

        result.push_back(std::make_shared<JsonMap>(response));
    }

    output << JsonArray(result).ToString();
}


void TransportGuideManager::AddStop(const BusStop& stop)
{
    stops_database_.AddStop(stop);
}


void TransportGuideManager::AddRoute(
        const std::string& bus_name, const std::shared_ptr<IRouteInfo>& route_info)
{
    routes_database_.AddRoot(bus_name, route_info);
}


void TransportGuideManager::WriteResponse(ResponseType response_type,
                                          const std::string& response_param, std::ostream& output) const
{
    switch (response_type)
    {
        case ResponseType::BUS:
            output << routes_database_.GetRouteStats(response_param) << '\n';
            break;

        case ResponseType::STOP:
            output << stops_database_.GetBusStopStat(response_param) << '\n';
            break;
    }
}
