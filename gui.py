#! /usr/bin/env python

# TODO: 
# Add logic to load .png files
# Add slider for movie
# add play/pause/stop button
# 
#
#

ANT_LOAD    = 1
ANT_EXIT    = 2
ANT_HELP    = 3
ANT_ABOUT   = 4
ANT_RUN     = 5
ANT_PAUSE   = 6
ANT_RESET   = 7
ANT_STOP    = 8



import wx
from wx.lib.wordwrap import wordwrap


class AntFrame(wx.Frame):
    def __init__(self):
        wx.Frame.__init__(self, None, -1, "AntViewer")
        
        menuFile = wx.Menu()
        menuFile.Append(ANT_LOAD, "Load")
        menuFile.AppendSeparator()
        menuFile.Append(ANT_EXIT, "E&xit")
        
        menuHelp = wx.Menu()
        menuHelp.Append(ANT_ABOUT, "About")
        
        
        menuBar = wx.MenuBar()
        menuBar.Append(menuFile, "&File")
        menuBar.Append(menuHelp, "&Help")
        
        self.SetMenuBar(menuBar)
        
        self.Bind(wx.EVT_MENU, self.OnAbout, id=ANT_ABOUT)
        self.Bind(wx.EVT_MENU, self.OnExit, id=ANT_EXIT)
        self.Bind(wx.EVT_MENU, self.OnLoad, id=ANT_LOAD)
        
        statusbar = self.CreateStatusBar()
        statusbar.SetFieldsCount(2)
        self.SetStatusText("Idle")
        
        panel=wx.Panel(self, -1)
        panel.Bind(wx.EVT_MOTION, self.OnMove)
        
        wx.StaticText(panel, -1, "Pos: ", pos=(10,10) )
        self.posCtrl = wx.TextCtrl(panel, -1, "", pos=(40,10) )

    def OnMove(self, event):
        pos=event.GetPosition()
        self.posCtrl.SetValue("%s, %s"%(pos.x, pos.y) )
    
    def OnLoad(self, event):
        dlg = wx.DirDialog(self, message="Choose XML Folder...", defaultPath="", style=0)
        if dlg.ShowModal() == wx.ID_OK:
            path=dlg.GetPath()
            print path
        dlg.Destroy()
        
        #example of PIL 2 wxPython convertion
        #source = Image.open( r"Z:\mcfport\portfoli\full\claire.jpg", 'r')
        #image = wx.EmptyImage( *source.size )
        #image.SetData( source.convert( "RGB").tostring() )
        
    def OnExit(self, event):
        self.Close()
             
    def OnAbout(self, event):
        info = wx.AboutDialogInfo()
        info.Name = "Ant Viewer"
        info.Description = wordwrap(
            "A simple Pharaoh's ant model viewer",
            350, wx.ClientDC(self))
        info.WebSite = ("http://com3001.googlecode.com", "Google Code page")
        info.Developers = [ "Brice Fernandes"]
        wx.AboutBox(info)
        
if __name__ == "__main__":
    app = wx.PySimpleApp()
    frame=AntFrame()
    frame.Show(True)
    app.MainLoop()
