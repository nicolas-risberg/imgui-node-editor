# define IMGUI_DEFINE_MATH_OPERATORS
# include "widgets.h"
# include <imgui_internal.h>

void ax::Widgets::Icon(const ImVec2& size, IconType type, bool filled, const ImVec4& color/* = ImVec4(1, 1, 1, 1)*/, const ImVec4& innerColor/* = ImVec4(0, 0, 0, 0)*/, const bool highlight)
{
	if (ImGui::IsRectVisible(size))
	{
		auto cursorPos = ImGui::GetCursorScreenPos();
		auto drawList = ImGui::GetWindowDrawList();

		if (!highlight)
		{
			ax::Drawing::DrawIcon(drawList, cursorPos, cursorPos + size, type, filled, ImColor(color), ImColor(innerColor));
		}
		else
		{
			ImRect rect = ImRect(cursorPos, cursorPos + size);
			rect.Expand(3.14f);
			ax::Drawing::DrawIcon(drawList, rect.Min, rect.Max, type, filled, ImColor(color), ImColor(innerColor));
		}
	}

	ImGui::Dummy(size);
}