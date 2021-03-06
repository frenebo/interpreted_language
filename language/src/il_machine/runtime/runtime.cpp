#include <vector>
#include <variant>
#include <iostream>

#include "runtime.hpp"
#include "../../intermediate_lang/instructions/instructions.hpp"
#include "../stack/stack.hpp"
#include "../values/values.hpp"
#include "../il_runtime_exception.hpp"

namespace il_machine::runtime
{
    // @TODO runtime options
    IlRuntime::IlRuntime(
            il_machine::stack::IlStack stack,
            il_machine::instruction_memory::InstructionMemory instruction_memory
        )
    : _stack(stack),
    _instruction_memory(instruction_memory)
    {
    }

    void IlRuntime::start()
    {
        for (auto instruction_cont : _instruction_memory.instruction_containers())
        {
            if (std::holds_alternative<intermediate_lang::instructions::IntAddInstruction>(instruction_cont.contained_instruction()))
            {
                execute_add_ints();
            }
            else if (std::holds_alternative<intermediate_lang::instructions::IntSubtractInstruction>(instruction_cont.contained_instruction()))
            {
                execute_subtract_ints();
            }
            else if (std::holds_alternative<intermediate_lang::instructions::LoadConstNumberInstruction>(instruction_cont.contained_instruction()))
            {
                execute_load_const_num(std::get<intermediate_lang::instructions::LoadConstNumberInstruction>(instruction_cont.contained_instruction()));
            }
            else if (std::holds_alternative<intermediate_lang::instructions::LogValueInstruction>(instruction_cont.contained_instruction()))
            {
                execute_log_value();
            }
            else if (std::holds_alternative<intermediate_lang::instructions::LoadConstStringInstruction>(instruction_cont.contained_instruction()))
            {
                execute_load_const_string(std::get<intermediate_lang::instructions::LoadConstStringInstruction>(instruction_cont.contained_instruction()));
            }
            else
            {
                throw IlRuntimeException("Unimplemented instruction");
            }
        }
    }

    void IlRuntime::execute_log_value()
    {
        auto stack_val = _stack.pop();

        if (std::holds_alternative<il_machine::values::IlIntValue>(stack_val.contained_value()))
        {
            double contained_num = std::get<il_machine::values::IlIntValue>(stack_val.contained_value()).contained_num();

            std::cout << "LOG: " << contained_num << "\n";
        }
        else if (std::holds_alternative<il_machine::values::IlStringValue>(stack_val.contained_value()))
        {
            std::string contained_str = std::get<il_machine::values::IlStringValue>(stack_val.contained_value()).contained_string();

            std::cout << "LOG: " << contained_str << "\n";
        }
        else
        {
            std::cout << "Unimplemented log value\n";
        }
    }

    void IlRuntime::execute_load_const_string(intermediate_lang::instructions::LoadConstStringInstruction instruction)
    {
        il_machine::values::IlStringValue str_val = il_machine::values::IlStringValue(instruction.get_value());
        il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(str_val);

        _stack.push(val_container);
    }

    void IlRuntime::execute_load_const_num(intermediate_lang::instructions::LoadConstNumberInstruction instruction)
    {
        // double num_val = instruction.get_value();

        il_machine::values::IlIntValue num_val = il_machine::values::IlIntValue(instruction.get_value());
        il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(num_val);

        _stack.push(val_container);
    }

    void IlRuntime::execute_subtract_ints()
    {
        auto rhs = _stack.pop();
        auto lhs = _stack.pop();

        if (
            std::holds_alternative<il_machine::values::IlIntValue>(rhs.contained_value()) &&
            std::holds_alternative<il_machine::values::IlIntValue>(lhs.contained_value()))
        {
            double rhs_num = std::get<il_machine::values::IlIntValue>(rhs.contained_value()).contained_num();
            double lhs_num = std::get<il_machine::values::IlIntValue>(lhs.contained_value()).contained_num();

            il_machine::values::IlIntValue new_val = il_machine::values::IlIntValue(lhs_num - rhs_num);

            il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(new_val);
            _stack.push(val_container);

        }
        else
        {
            throw il_machine::IlRuntimeException("Cannot subtract two values that are not both of number type");
        }
    }

    void IlRuntime::execute_add_ints()
    {
        auto rhs = _stack.pop();
        auto lhs = _stack.pop();

        if (
            std::holds_alternative<il_machine::values::IlIntValue>(rhs.contained_value()) &&
            std::holds_alternative<il_machine::values::IlIntValue>(lhs.contained_value()))
        {
            double rhs_num = std::get<il_machine::values::IlIntValue>(rhs.contained_value()).contained_num();
            double lhs_num = std::get<il_machine::values::IlIntValue>(lhs.contained_value()).contained_num();

            il_machine::values::IlIntValue new_val = il_machine::values::IlIntValue(lhs_num + rhs_num);

            il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(new_val);
            _stack.push(val_container);
        }
        else
        {
            throw il_machine::IlRuntimeException("Cannot add two values that are not both of number type");
        }
    }
}
