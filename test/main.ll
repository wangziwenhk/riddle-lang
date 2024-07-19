; ModuleID = 'main'
source_filename = "main"

@0 = private unnamed_addr constant [3 x i8] c"%c\00", align 1

declare i32 @printf(ptr, ...)

define i32 @main() {
entry:
  %a = alloca i8, align 1
  store i32 97, ptr %a, align 4
  %tempVar = load ptr, ptr %a, align 8
  %0 = call i32 (ptr, ...) @printf(ptr @0, ptr %tempVar)
  ret i32 0
}