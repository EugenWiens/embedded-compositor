#ifndef EMBEDDEDSHELL_H
#define EMBEDDEDSHELL_H
#include "embeddedshellsurface.h"
#include <QObject>
#include <QtWaylandClient/private/qwaylandclientextension_p.h>

class EmbeddedShellPrivate;
namespace QtWayland {
class embedded_shell;
}

namespace QtWaylandClient {
class QWaylandWindow;
}

class EmbeddedShell : QWaylandClientExtension {
  Q_OBJECT
  QtWayland::embedded_shell *instance;

public:
  bool isActive() { return QWaylandClientExtension::isActive(); }
  EmbeddedShell();
  EmbeddedShellSurface *createSurface(QtWaylandClient::QWaylandWindow *window,
                                      EmbeddedShellSurface::Anchor anchor, uint32_t margin);
  const struct wl_interface *extensionInterface() const override;
  void bind(struct ::wl_registry *registry, int id, int ver) override;
};

#endif // EMBEDDEDSHELL_H
