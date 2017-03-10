= FluidPlug - SoundFonts as LV2 plugins via FluidSynth by falkTX =
== Extended generic implementation by dcoredump ==

> Usage:
> 
> 	./genericfluidplug
> 		[-boxy-style=<color>] 
> 		[-knob-style=<color>]
> 		<SF2-soundfont>
> 		<FluidPlug-name>
> 		<LV2-install-path>
 
(`-boxy-style` and `-knob-style` are only working when you have installed
mod-sdk (see https://github.com/moddevices/mod-sdk) and if you have set the
environment-variable MODSDK pointing to your installation).

=Example generic installation for Zynthian=

> apt-get install -y templatetoolkit-perl 
> git clone https://github.com/dcoredump/GenericFluidPlug
> cd GenericFluidPlug
> perl ./genericfluidplug <path_to_my_sf2_file> <path_and_name_for_LV2_source_code> <path_and_name_for_LV2_plugin>
> cd <path_and_name_for_LV2_source_code>
> make DEST=/zynthian/zynthian-plugins/lv2 install
> systemctl restart mod-host && systemctl restart mod-ui

= Example installation (with real data and pathnames =

> # install system package (only needed the first time)
> apt-get install -y templatetoolkit-perl 
> # get your favorite soundfont and put it to /tmp and unzip it
> cd /tmp
> wget http://rkhive.com/new/new_banks/masterpiece.zip    
> unzip masterpiece.zip
> # get the magic builder software (only needed the first time)
> cd /zynthian/zynthian-sw/plugins
> git clone https://github.com/dcoredump/GenericFluidPlug
> # generate your Fluidplug source code
> cd GenericFluidPlug
> perl ./genericfluidplug /tmp/Masterpiece.sf2 /zynthian/zynthian-sw/plugins/Masterpiece /zynthian/zynthian-plugins/lv2
> cd /zynthian/zynthian-sw/plugins/Masterpiece
> make install
> systemctl restart mod-host && systemctl restart mod-ui

