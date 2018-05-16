executors := console
console_path := src/console
console_dep := -lplugin -lcommon -llib -lbus -llifecycle -lipc -lps -lattestor \
	-lheartbeat -llearning -lmemory -lspl -lbarren -lid_service -ltimer \
	-lbarren_cache -lconfig_center -lplugin_controller -lgower -lexecutor

modules := plugin common lib bus lifecycle ipc ps attestor heartbeat learning \
	memory spl barren id_service timer barren_cache config_center \
	plugin_controller gower executor
plugin_controller_path := src/plugin_controller
plugin_controller_dep := -lplugin -llib -lcommon
gower_path := src/gower
gower_dep := -lplugin -lipc -llib
config_center_path := src/config_center
config_center_dep := -lplugin -llib
barren_cache_path := src/barren_cache
barren_cache_dep := -lplugin -lipc -llib -lbarren
timer_path := src/timer
timer_dep := -lplugin
id_service_path := src/id_service
id_service_dep := -lplugin -lipc -llib
executor_path := src/executor
executor_dep := -lplugin -llib -lbarren -lipc
barren_path := src/barren
barren_dep := -lplugin -llib -lipc -lcommon
spl_path := src/spl
spl_dep := -lplugin
memory_path := src/memory
memory_dep := -lplugin -llib -lbarren
learning_path := src/learning
learning_dep := -lplugin
heartbeat_path := src/heartbeat
heartbeat_dep := -lplugin -llib -lipc
attestor_path := src/attestor
attestor_dep := -lplugin
ps_path := src/ps
ps_dep := -lplugin
ipc_path := src/ipc
ipc_dep := -lps -lplugin
lifecycle_path := src/lifecycle
lifecycle_dep := -lplugin -llib -lcommon -lipc
common_path := src/common
common_dep := -llib -lplugin
bus_path := src/bus
bus_dep := -lcommon -lplugin
lib_path := src/lib
lib_dep_third := -lleveldb
plugin_path = src/plugin
plugin_dep := -llib

modules_var := $(patsubst %,$(objout)/m-%.mk, $(modules))
libraries := $(patsubst %,$(libout)/lib%.dylib, $(modules))
executors_var := $(patsubst %,$(objout)/b-%.mk, $(executors))
binaries := $(patsubst %,$(binout)/%, $(executors))

sinclude $(modules_var)
include $(executors_var)
sinclude $(dep)

$(objout)/b-%.mk: 
	@mkdir -p $(objout) $(libout) $(binout)
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_src := $$(shell find $($(patsubst $(objout)/b-%.mk,%_path, $@)) -name "*.cpp")' > $@
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_obj := $$(patsubst %.cpp, $$(objout)/%.o, $$($(patsubst $(objout)/b-%.mk,%_src, $@)))' >> $@
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_dep_build := $$(patsubst -l%, $$(libout)/lib%.dylib, $$($(patsubst $(objout)/b-%.mk,%_dep, $@)))' >> $@
	@echo 'dep := $$(dep) $$(patsubst%.cpp, $$(objout)/%.d, $$($(patsubst $(objout)/b-%.mk,%, $@)_src))' >> $@
	@echo '$$(binout)/$(patsubst $(objout)/b-%.mk,%, $@): $$($(patsubst $(objout)/b-%.mk,%, $@)_dep_build) $$($(patsubst $(objout)/b-%.mk,%, $@)_obj)' >> $@
	@echo '\t$$(CC) $$(LDFLAGS) $$($(patsubst $(objout)/b-%.mk,%, $@)_dep) $$($(patsubst $(objout)/b-%.mk,%, $@)_dep_third) -o $$(binout)/$(patsubst $(objout)/b-%.mk,%, $@) $$($(patsubst $(objout)/b-%.mk,%, $@)_obj)' >> $@
	@find $($(patsubst $(objout)/b-%.mk,%_path, $@)) -type d -exec mkdir -p $(objout)/{} \;

$(objout)/m-%.mk: 
	@mkdir -p $(objout) $(libout) $(binout)
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_src := $$(shell find $($(patsubst $(objout)/m-%.mk,%_path, $@)) -name "*.cpp")' > $@
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_obj := $$(patsubst %.cpp, $$(objout)/%.o, $$($(patsubst $(objout)/m-%.mk,%_src, $@)))' >> $@
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_dep_build := $$(patsubst -l%, $$(libout)/lib%.dylib, $$($(patsubst $(objout)/m-%.mk,%_dep, $@)))' >> $@
	@echo 'dep := $$(dep) $$(patsubst%.cpp, $$(objout)/%.d, $$($(patsubst $(objout)/m-%.mk,%, $@)_src))' >> $@
	@echo '$$(libout)/lib$(patsubst $(objout)/m-%.mk,%, $@).dylib: $$($(patsubst $(objout)/m-%.mk,%, $@)_dep_build) $$($(patsubst $(objout)/m-%.mk,%, $@)_obj)' >> $@
	@echo '\t$$(CC) -shared -fPIC $$(LDFLAGS) $$($(patsubst $(objout)/m-%.mk,%, $@)_dep) $$($(patsubst $(objout)/m-%.mk,%, $@)_dep_third) -o $$(libout)/lib$(patsubst $(objout)/m-%.mk,%, $@).dylib $$($(patsubst $(objout)/m-%.mk,%, $@)_obj)' >> $@
	@find $($(patsubst $(objout)/m-%.mk,%_path, $@)) -type d -exec mkdir -p $(objout)/{} \;
	
$(objout)/%.d : %.cpp
	$(CC) -MT"$(objout)/$(<:.cpp=.o)" -MM $(CXXFLAGS) $(CPPFLAGS) $< > $@

$(objout)/%.o : %.cpp
	$(CC) -c $(CXXFLAGS) -o $@ $<


