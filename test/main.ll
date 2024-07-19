; ModuleID = 'main'
source_filename = "main"

@0 = private unnamed_addr constant [3 x i8] c"%d\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %a = alloca i32, align 4
  store i32 1, ptr %a, align 4
  %loadedVar = load ptr, ptr %a, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @0, ptr %loadedVar)
  ret i32 0
}