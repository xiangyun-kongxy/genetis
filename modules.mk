executors := console visual_plus spl
console_path := src/util/console
console_dep := -lplugin -lcommon -llib -lbus -llifecycle -lipc -lps -lleveldb
visual_plus_path := src/app/visual_plus
visual_plus_dep := -llib
spl_path := src/app/spl
spl_dep := -lplugin

modules := plugin common lib bus lifecycle ipc ps attestor heartbeat learning \
	memory barren id_service timer barren_cache config_center \
	plugin_controller gower executor leveldb
leveldb_path := third_part/leveldb
plugin_controller_path := src/util/plugin_controller
plugin_controller_dep := -lplugin -llib -lcommon
gower_path := src/app/mind/gower
gower_dep := -lplugin -lipc -llib
config_center_path := src/util/config_center
config_center_dep := -lplugin -llib
barren_cache_path := src/app/mind/barren_cache
barren_cache_dep := -lplugin -lipc -llib -lbarren
timer_path := src/util/timer
timer_dep := -lplugin
id_service_path := src/util/id_service
id_service_dep := -lplugin -lipc -llib
executor_path := src/app/mind/executor
executor_dep := -lplugin -llib -lbarren -lipc
barren_path := src/app/mind/barren
barren_dep := -lplugin -llib -lipc -lcommon
memory_path := src/app/mind/memory
memory_dep := -lplugin -llib -lbarren
learning_path := src/app/mind/learning
learning_dep := -lplugin
heartbeat_path := src/util/heartbeat
heartbeat_dep := -lplugin -llib -lipc
attestor_path := src/app/mind/attestor
attestor_dep := -lplugin
ps_path := src/frame/ps
ps_dep := -lplugin -llib
ipc_path := src/frame/ipc
ipc_dep := -lps -lplugin
lifecycle_path := src/frame/lifecycle
lifecycle_dep := -lplugin -llib -lcommon -lipc
common_path := src/common
common_dep := -llib -lplugin
bus_path := src/frame/bus
bus_dep := -lcommon -lplugin -llib
lib_path := src/lib
lib_dep := -lleveldb
plugin_path = src/frame/plugin
plugin_dep := -llib

modules_var := $(patsubst %,$(objout)/m-%.mk, $(modules))
libraries := $(patsubst %,$(libout)/lib%.$(libext), $(modules))
executors_var := $(patsubst %,$(objout)/b-%.mk, $(executors))
binaries := $(patsubst %,$(binout)/%, $(executors))

sinclude $(modules_var)
sinclude $(executors_var)
sinclude $(dep)

$(objout)/b-%.mk: 
	@mkdir -p $(objout) $(libout) $(binout)
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_src := $$(shell find $($(patsubst $(objout)/b-%.mk,%_path, $@)) -name '*.cpp')' > $@
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_obj := $$(patsubst %.cpp, $$(objout)/%.o, $$($(patsubst $(objout)/b-%.mk,%_src, $@)))' >> $@
	@echo '$(patsubst $(objout)/b-%.mk,%, $@)_dep_build := $$(patsubst -l%, $$(libout)/lib%.$(libext), $$($(patsubst $(objout)/b-%.mk,%_dep, $@)))' >> $@
	@echo 'dep := $$(dep) $$(patsubst %.cpp, $$(objout)/%.d, $$($(patsubst $(objout)/b-%.mk,%, $@)_src))' >> $@
	@echo '$$(binout)/$(patsubst $(objout)/b-%.mk,%, $@): $$($(patsubst $(objout)/b-%.mk,%, $@)_dep_build) $$($(patsubst $(objout)/b-%.mk,%, $@)_obj)' >> $@
	@echo '	@echo linking $$@' >> $@
	@echo '	@$$(CC) $$(LDFLAGS) $$($(patsubst $(objout)/b-%.mk,%, $@)_dep) $$($(patsubst $(objout)/b-%.mk,%, $@)_dep_third) -o $$(binout)/$(patsubst $(objout)/b-%.mk,%, $@) $$($(patsubst $(objout)/b-%.mk,%, $@)_obj)' >> $@
	@find $($(patsubst $(objout)/b-%.mk,%_path, $@)) -type d -exec mkdir -p $(objout)/{} \;

$(objout)/m-%.mk: 
	@mkdir -p $(objout) $(libout) $(binout)
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_src := $$(shell find $($(patsubst $(objout)/m-%.mk,%_path, $@)) -name '*.cpp')' > $@
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_obj := $$(patsubst %.cpp, $$(objout)/%.o, $$($(patsubst $(objout)/m-%.mk,%_src, $@)))' >> $@
	@echo '$(patsubst $(objout)/m-%.mk,%, $@)_dep_build := $$(patsubst -l%, $$(libout)/lib%.$(libext), $$($(patsubst $(objout)/m-%.mk,%_dep, $@)))' >> $@
	@echo 'dep := $$(dep) $$(patsubst %.cpp, $$(objout)/%.d, $$($(patsubst $(objout)/m-%.mk,%, $@)_src))' >> $@
	@echo '$$(libout)/lib$(patsubst $(objout)/m-%.mk,%, $@).$(libext): $$($(patsubst $(objout)/m-%.mk,%, $@)_dep_build) $$($(patsubst $(objout)/m-%.mk,%, $@)_obj)' >> $@
	@echo '	@echo linking $$@' >> $@
	@echo '	@$$(CC) -shared -fPIC $$(LDFLAGS) $$($(patsubst $(objout)/m-%.mk,%, $@)_dep) $$($(patsubst $(objout)/m-%.mk,%, $@)_dep_third) -o $$(libout)/lib$(patsubst $(objout)/m-%.mk,%, $@).$(libext) $$($(patsubst $(objout)/m-%.mk,%, $@)_obj)' >> $@
	@find $($(patsubst $(objout)/m-%.mk,%_path, $@)) -type d -exec mkdir -p $(objout)/{} \;
	
$(objout)/%.d : %.cpp
	@$(CC) -MT'$(objout)/$(<:.cpp=.o) $(objout)/$(<:.cpp=.d)' -MM $(CXXFLAGS) $(CPPFLAGS) $< > $@

$(objout)/%.o : %.cpp
	@echo cc -o $@ $<
	@$(CC) -c $(CXXFLAGS) -o $@ $<


