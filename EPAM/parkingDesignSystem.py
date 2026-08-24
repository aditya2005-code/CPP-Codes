import heapq
from abc import ABC, abstractmethod
from enum import Enum
from datetime import datetime


# =========================
# ENUMS
# =========================

class VehicleType(Enum):
    EV = "EV"
    REGULAR = "REGULAR"


# =========================
# SLOT
# =========================

class Slot(ABC):
    def __init__(self, sid, slot_type):
        self.sid = sid
        self.slot_type = slot_type

    # Required so Slot objects can be stored in heapq
    def __lt__(self, other):
        return self.sid < other.sid

    def is_compatible(self, vehicle):
        return self.slot_type == vehicle.vehicle_type

    @abstractmethod
    def provide_service(self, vehicle):
        pass


class EVSlot(Slot):
    def __init__(self, sid):
        super().__init__(sid, VehicleType.EV)

    def provide_service(self, vehicle):
        print(f"Charging EV: {vehicle.vname}")


class RegularSlot(Slot):
    def __init__(self, sid):
        super().__init__(sid, VehicleType.REGULAR)

    def provide_service(self, vehicle):
        print(f"Regular parking service for: {vehicle.vname}")


# =========================
# VEHICLE
# =========================

class Vehicle(ABC):
    def __init__(self, vid, vname):
        self.vid = vid
        self.vname = vname

    @property
    @abstractmethod
    def vehicle_type(self):
        pass


class EV(Vehicle):
    @property
    def vehicle_type(self):
        return VehicleType.EV


class RegularVehicle(Vehicle):
    @property
    def vehicle_type(self):
        return VehicleType.REGULAR


# =========================
# PARKING TICKET
# =========================

class ParkingTicket:
    def __init__(self, ticket_id, vehicle, slot):
        self.ticket_id = ticket_id
        self.vehicle = vehicle
        self.slot = slot
        self.entry_time = datetime.now()
        self.exit_time = None

    def close_ticket(self):
        self.exit_time = datetime.now()

    def get_duration(self):
        end_time = self.exit_time or datetime.now()
        return end_time - self.entry_time


# =========================
# PARKING SYSTEM
# =========================

class ParkingSystem:

    def __init__(self, pid):
        self.pid = pid

        # Separate heaps based on slot type
        self.available_slots = {
            VehicleType.EV: [],
            VehicleType.REGULAR: []
        }

        # vehicle_id -> ParkingTicket
        self.active_tickets = {}

        self.ticket_counter = 1


    def add_slot(self, slot):

        heapq.heappush(
            self.available_slots[slot.slot_type],
            slot
        )

        print(
            f"Added {slot.slot_type.value} "
            f"slot: {slot.sid}"
        )


    def park(self, vehicle):

        # Prevent duplicate parking
        if vehicle.vid in self.active_tickets:
            print(f"{vehicle.vname} is already parked")
            return None

        vehicle_type = vehicle.vehicle_type

        slot_heap = self.available_slots.get(vehicle_type)

        # No compatible slot available
        if not slot_heap:
            print(
                f"No {vehicle_type.value} "
                f"slot available"
            )
            return None

        # Get minimum slot ID
        slot = heapq.heappop(slot_heap)

        # Create parking ticket
        ticket = ParkingTicket(
            self.ticket_counter,
            vehicle,
            slot
        )

        self.ticket_counter += 1

        # Store active ticket
        self.active_tickets[vehicle.vid] = ticket

        print(
            f"{vehicle.vname} parked at "
            f"Slot {slot.sid}"
        )

        print(
            f"Ticket ID: {ticket.ticket_id}"
        )

        # Slot-specific behavior
        slot.provide_service(vehicle)

        return ticket


    def leave(self, vehicle_id):

        # Get and remove active ticket
        ticket = self.active_tickets.pop(
            vehicle_id,
            None
        )

        if ticket is None:
            print("Vehicle is not parked")
            return None

        # Close ticket
        ticket.close_ticket()

        slot = ticket.slot

        # Return slot to correct heap
        heapq.heappush(
            self.available_slots[slot.slot_type],
            slot
        )

        print(
            f"{ticket.vehicle.vname} "
            f"left Slot {slot.sid}"
        )

        print(
            f"Parking duration: "
            f"{ticket.get_duration()}"
        )

        return ticket


    def show_available_slots(self):

        print("\nAVAILABLE SLOTS")

        for slot_type, heap in self.available_slots.items():

            slot_ids = sorted(
                slot.sid for slot in heap
            )

            print(
                f"{slot_type.value}: "
                f"{slot_ids}"
            )


    def show_parked_vehicles(self):

        print("\nPARKED VEHICLES")

        if not self.active_tickets:
            print("No vehicles parked")
            return

        for ticket in self.active_tickets.values():

            print(
                f"Vehicle: {ticket.vehicle.vname}, "
                f"Slot: {ticket.slot.sid}, "
                f"Ticket: {ticket.ticket_id}"
            )


# =========================
# MAIN
# =========================

def main():

    parking = ParkingSystem(1)

    # -----------------
    # ADD SLOTS
    # -----------------

    parking.add_slot(EVSlot(1))
    parking.add_slot(EVSlot(3))
    parking.add_slot(EVSlot(5))

    parking.add_slot(RegularSlot(2))
    parking.add_slot(RegularSlot(4))
    parking.add_slot(RegularSlot(6))

    # -----------------
    # CREATE VEHICLES
    # -----------------

    ev1 = EV(101, "Tesla")

    regular1 = RegularVehicle(
        102,
        "BMW"
    )

    ev2 = EV(
        103,
        "Tata Nexon"
    )

    # -----------------
    # PARK VEHICLES
    # -----------------

    print("\n--- PARKING ---")

    parking.park(ev1)

    parking.park(regular1)

    parking.park(ev2)

    # -----------------
    # SHOW STATUS
    # -----------------

    parking.show_parked_vehicles()

    parking.show_available_slots()

    # -----------------
    # VEHICLE LEAVES
    # -----------------

    print("\n--- VEHICLE LEAVING ---")

    parking.leave(101)

    # -----------------
    # SHOW UPDATED STATUS
    # -----------------

    parking.show_parked_vehicles()

    parking.show_available_slots()


if __name__ == "__main__":
    main()