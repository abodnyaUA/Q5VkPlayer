#!/usr/bin/env python
#
# Copyright 2009-2012 Canonical Ltd.
#
# Authors: Neil Jagdish Patel <neil.patel@canonical.com>
#          Jono Bacon <jono@ubuntu.com>
#          David Planella <david.planella@ubuntu.com>
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of either or both of the following licenses:
#
# 1) the GNU Lesser General Public License version 3, as published by the
# Free Software Foundation; and/or
# 2) the GNU Lesser General Public License version 2.1, as published by
# the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranties of
# MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
# PURPOSE.  See the applicable version of the GNU Lesser General Public
# License for more details.
#
# You should have received a copy of both the GNU Lesser General Public
# License version 3 and version 2.1 along with this program.  If not, see
# <http://www.gnu.org/licenses/>
#

import sys
import dbus
from traceback import print_exc
from gi.repository import Gtk
from gi.repository import AppIndicator3 as appindicator
import os
import dbus.service
from dbus.mainloop.glib import DBusGMainLoop

class MyDBUSService(dbus.service.Object):
	def __init__(self):
		bus_name = dbus.service.BusName('org.mpris.MediaPlayer2.qvkplayer.icon', bus=dbus.SessionBus())
		dbus.service.Object.__init__(self, bus_name, '/org/mpris/MediaPlayer2')

	@dbus.service.method('org.mpris.MediaPlayer2')
	def Quit(self):
		Gtk.main_quit()

DBusGMainLoop(set_as_default=True)
bus = dbus.SessionBus()
playerControl = bus.get_object("org.mpris.MediaPlayer2.qvkplayer.mainwindow", "/org/mpris/MediaPlayer2")

 
def exitFromPlayer(w):
	playerControl.Quit(dbus_interface='org.mpris.MediaPlayer2')
	Gtk.main_quit()

def playNextSong(w):
	playerControl.Next(dbus_interface='org.mpris.MediaPlayer2.Player')

def playPrevSong(w):
	playerControl.Previous(dbus_interface='org.mpris.MediaPlayer2.Player')

def playPause(w):
	playerControl.PlayPause(dbus_interface='org.mpris.MediaPlayer2.Player')

def showPlayer(w):
	playerControl.Raise(dbus_interface='org.mpris.MediaPlayer2') 



if __name__ == "__main__":
	myservice = MyDBUSService()

	ind = appindicator.Indicator.new (
						"example-simple-client",
						"/home/kazak/QVkPlayer/qvk.svg",
						appindicator.IndicatorCategory.APPLICATION_STATUS)
	ind.set_status (appindicator.IndicatorStatus.ACTIVE)
	ind.set_attention_icon ("indicator-messages-new")
 
	# create a menu
	menu = Gtk.Menu()

	#creating menu items
	showPlayerItem = "Show player"
	showItem = Gtk.MenuItem(showPlayerItem) 
	menu.append(showItem)
	
	nextSongItem = "Next"
	nextItem = Gtk.MenuItem(nextSongItem) 
	menu.append(nextItem)
	
	previousSongItem = "Previous"
	prevItem = Gtk.MenuItem(previousSongItem) 
	menu.append(prevItem)
	
	playPauseItem = "Play/Pause"
	ppItem = Gtk.MenuItem(playPauseItem) 
	menu.append(ppItem)
	
	exitItem = "Exit"
	exitMenuItem = Gtk.MenuItem(exitItem) 
	menu.append(exitMenuItem)
	
	# this is where you would connect your menu item up with a function:	
	exitMenuItem.connect("activate", exitFromPlayer)
	showItem.connect("activate", showPlayer)
	nextItem.connect("activate", playNextSong)
	prevItem.connect("activate", playPrevSong)
	ppItem.connect("activate", playPause)
	
	# show the items
	showItem.show()
	nextItem.show()
	prevItem.show()
	ppItem.show()
	exitMenuItem.show()
	
	ind.set_menu(menu)
	Gtk.main()
