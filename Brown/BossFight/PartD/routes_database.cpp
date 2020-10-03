#include "routes_database.h"


void RoutesDataBase::BuildAllRoutes(BusStopsDataBase& stops_database)
{
    for (auto& pair_ : routes_)
    {
        pair_.second->Build(stops_database, pair_.first);
    }
}


RoutesDataBase::RouteResponse RoutesDataBase::GetRouteStats(const std::string& bus) const
{
    RouteResponse response;
    response.first = bus;

    const auto finder = routes_.find(bus);

    if (finder != routes_.end())
    {
        response.second = finder->second->GetRouteStats();
    }

    return response;
}


std::ostream& operator<<(std::ostream& output, const RoutesDataBase::RouteResponse& response)
{
    output.precision(6);

    output << "Bus " << response.first << ": ";

    if (response.second)
    {
        output << response.second->stops_on_route << " stops on route, " <<
               response.second->unique_stops << " unique stops, " <<
               response.second->route_length << " route length, " <<
               response.second->curvature << " curvature";
    }
    else
    {
        output << "not found";
    }

    return output;
}


void RoutesDataBase::AddRoot(const std::string& bus_name, const std::shared_ptr<IRouteInfo>& route_info){
    routes_[bus_name] = route_info;
}


void IRouteInfo::AddStop(const std::string& stop)
{
    stops_.push_back(stop);
    unique_stops_.insert(stop);
}


const RouteStats& IRouteInfo::GetRouteStats() const
{
    return route_stats_;
}


void DirectRoute::RecomputeStatsInChildClass(const BusStopsDataBase& stops_database)
{
    for (size_t i = stops_.size() - 1; i > 0; --i)
    {
        route_stats_.route_length +=
                stops_database.ComputeRealDistanceBetweenStops(stops_[i], stops_[i - 1]);
    }

    route_stats_.direct_distance *= 2;
    route_stats_.stops_on_route = 2 * stops_.size() - 1;
}


void RoundRoute::RecomputeStatsInChildClass(const BusStopsDataBase& stops_database)
{
    route_stats_.stops_on_route = stops_.size();
}


void IRouteInfo::Build(BusStopsDataBase& stops_database, const std::string& route_name)
{
    if (stops_.empty())
        return;

    if (stops_.size() == 1)
    {
        route_stats_.stops_on_route = 1;
        route_stats_.unique_stops = 1;
        route_stats_.route_length = 0;
    }
    else
    {
        for (size_t i = 0; i < stops_.size() - 1; ++i)
        {
            route_stats_.route_length +=
                    stops_database.ComputeRealDistanceBetweenStops(stops_[i], stops_[i + 1]);

            route_stats_.direct_distance +=
                    stops_database.ComputeDirectDistanceBetweenStops(stops_[i], stops_[i + 1]);

            stops_database.AddBusOnStop(route_name, stops_[i]);
        }
        stops_database.AddBusOnStop(route_name, *stops_.crbegin());

        RecomputeStatsInChildClass(stops_database);

        route_stats_.unique_stops = unique_stops_.size();

        route_stats_.curvature = route_stats_.route_length / route_stats_.direct_distance;
    }
}
