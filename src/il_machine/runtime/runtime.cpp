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
            if (std::holds_alternative<intermediate_lang::instructions::AddNumbersInstruction>(instruction_cont.contained_instruction()))
            {
                execute_add_numbers();
            }
            else if (std::holds_alternative<intermediate_lang::instructions::LoadConstNumberInstruction>(instruction_cont.contained_instruction()))
            {
                execute_load_const_num(std::get<intermediate_lang::instructions::LoadConstNumberInstruction>(instruction_cont.contained_instruction()));
            }
            else if (std::holds_alternative<intermediate_lang::instructions::LogValueInstruction>(instruction_cont.contained_instruction()))
            {
                execute_log_value();
            }
            else
            {
                throw IlRuntimeException("Unimplemented instruction");
            }
        }
        // _instruction_memory.memory_
    }

    void IlRuntime::execute_log_value()
    {
        auto stack_val = _stack.pop();

        if (std::holds_alternative<il_machine::values::IlNumberValue>(stack_val.contained_value()))
        {
            double contained_num = std::get<il_machine::values::IlNumberValue>(stack_val.contained_value()).contained_num();

            std::cout << "LOG: " << contained_num << "\n";
        }
    }

    void IlRuntime::execute_load_const_num(intermediate_lang::instructions::LoadConstNumberInstruction instruction)
    {
        // double num_val = instruction.get_value();

        il_machine::values::IlNumberValue num_val = il_machine::values::IlNumberValue(instruction.get_value());
        il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(num_val);

        _stack.push(val_container);
    }

    void IlRuntime::execute_add_numbers()
    {
        auto rhs = _stack.pop();
        auto lhs = _stack.pop();

        if (
            std::holds_alternative<il_machine::values::IlNumberValue>(rhs.contained_value()) &&
            std::holds_alternative<il_machine::values::IlNumberValue>(lhs.contained_value()))
        {
            double rhs_num = std::get<il_machine::values::IlNumberValue>(rhs.contained_value()).contained_num();
            double lhs_num = std::get<il_machine::values::IlNumberValue>(lhs.contained_value()).contained_num();

            il_machine::values::IlNumberValue new_val = il_machine::values::IlNumberValue(rhs_num + lhs_num);

            il_machine::values::IlValueContainer val_container = il_machine::values::IlValueContainer(new_val);
            _stack.push(val_container);
        }
        else
        {
            throw il_machine::IlRuntimeException("Cannot add two values that are not both of number type");
        }
    }
}
