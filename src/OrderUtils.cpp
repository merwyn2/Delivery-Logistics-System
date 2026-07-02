#include "OrderUtils.h"

std::string statusToString(Status status)
{
    switch (status)
    {
        case Status::Pending:
            return "Pending";

        case Status::Approved:
            return "Approved";

        case Status::InTruck:
            return "InTruck";

        case Status::Delivered:
            return "Delivered";

        case Status::Cancelled:
            return "Cancelled";
    }

    return "Pending";
}

Status stringToStatus(const std::string& status)
{
    if (status == "Pending")
        return Status::Pending;

    if (status == "Approved")
        return Status::Approved;

    if (status == "InTruck")
        return Status::InTruck;

    if (status == "Delivered")
        return Status::Delivered;

    if (status == "Cancelled")
        return Status::Cancelled;

    return Status::Pending;
}