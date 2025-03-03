module;
export module Config.Init;
import Config.BasicOperator;
import Config.OperatorImpl;
export namespace Riddle::init {
    void init() {
        initBasicOpReType();
        initOperatorImpl();
    }
} // namespace Riddle::init
