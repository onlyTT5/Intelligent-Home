# 房间切换功能实现说明

## 功能描述
实现了通过下拉列表切换不同房间界面的功能：
- 选择"客厅" (索引0) -> 跳转到 Screen1
- 选择"主卧" (索引1) -> 跳转到 Screen2  
- 选择"次卧" (索引2) -> 跳转到 Screen3

## 修改文件列表

### 1. UI/ui_events.h
- 添加了 `roomChange(lv_event_t * e)` 函数声明

### 2. UI/ui_events.c
- 实现了 `roomChange()` 函数
- 该函数获取下拉列表的选择索引，根据索引跳转到对应的屏幕

### 3. UI/screens/ui_Screen1.c
- 添加了 `ui_event_ChangeRoom()` 事件处理函数
- 为下拉列表 `ui_ChangeRoom` 添加了事件回调

### 4. UI/screens/ui_Screen1.h
- 添加了 `ui_event_ChangeRoom()` 函数声明

### 5. UI/screens/ui_Screen2.c
- 添加了 `ui_event_ChangeRoom1()` 事件处理函数
- 为下拉列表 `ui_ChangeRoom1` 添加了事件回调

### 6. UI/screens/ui_Screen2.h
- 添加了 `ui_event_ChangeRoom1()` 函数声明

### 7. UI/screens/ui_Screen3.c
- 添加了 `ui_event_ChangeRoom2()` 事件处理函数
- 为下拉列表 `ui_ChangeRoom2` 添加了事件回调

### 8. UI/screens/ui_Screen3.h
- 添加了 `ui_event_ChangeRoom2()` 函数声明

## 实现原理

1. **事件触发**: 当用户点击下拉列表并选择选项时，触发 `LV_EVENT_VALUE_CHANGED` 事件
2. **获取选择**: 使用 `lv_dropdown_get_selected()` 函数获取用户选择的索引
3. **界面跳转**: 根据索引值调用 `lv_screen_load()` 函数加载对应的屏幕
   - 索引 0 (客厅) -> `lv_screen_load(ui_Screen1)`
   - 索引 1 (主卧) -> `lv_screen_load(ui_Screen2)`
   - 索引 2 (次卧) -> `lv_screen_load(ui_Screen3)`

## 使用方法
1. 编译项目：`make clean && make`
2. 运行程序：`./build/bin/main`
3. 点击界面上的房间选择下拉列表
4. 选择不同的房间选项来切换界面

## 注意事项
- 确保所有三个屏幕(Screen1, Screen2, Screen3)都已正确初始化
- 下拉列表选项的顺序必须与索引对应：客厅(0)、主卧(1)、次卧(2)
- 每个屏幕的下拉列表都可以独立切换到其他房间
